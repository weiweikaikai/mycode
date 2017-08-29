#include <async_serv/net_if.h>
#include<stdint.h>
#include<string.h>

#pragma pack(1)
//本结构用于打包发给 msgverif服务端
typedef struct msgverif_pkg{
   uint32_t len; //包的长度
   uint32_t id;//唯一ID 用于在msgverif服务器返回的时候找到原来的客户端
   char buf[];//client 发送的数据
}msgverif_pkg_t;
#pragma pack()

typedef struct client{
 uint32_t id; //标示客户端的唯一ID
 fdsession_t* fdsess;
}client_t;
enum{
//客户端连接的最大个数  在bench.conf里面配置了最多1024个连接数
 client_max_num =1024
};

//和 msgverif服务端的tcp连接socket fd 
static int msgverif_fd =-1;
//保存所有服务端连接
static client_t clients[client_max_num];
//从clients中获取一块空间保存客户端连接
static client_t * alloc_client(fdsession_t *fdsess);
//把空间返回给clients
static void dealloc_client(client_t *cli);
//根据客户端ID查找
static client_t *find_client_by_id(uint32_t id);
//根据客户端fd查找
static client_t *find_client_by_fd(int fd);



int	get_pkg_len(int fd, const void* pkg, int pkglen, int isparent)
{
	if (isparent) {
		int i;
		// 客户端的连接由父进程处理，包括accept、收发数据和关闭连接
		// 所以必须在父进程里才能获取客户端发送过来的字符串的长度
		const char* str = pkg;
		for (i = 0; (i != pkglen) && (str[i] != '\0'); ++i) ;

		if (i != pkglen) {
			return i + 1;
		}
	}else //子进程
    {
       //解析从msgverif服务端返回的报文长度
       if(fd == msgverif_fd)
       {
         //可用数据不足4个字节 不能解析出报文长度 
         if(pkglen <4){
            return 0;
         }
       }
       const msgverif_pkg_t * msgpkg =pkg;
        //如果报文中len ＜报文长度 则说明是个非法报文
        if(msgpkg->len <= sizeof(msgverif_pkg_t)) //注意sizeof返回uint
            return -1;
        
        return (int)msgpkg->len;
    }
	return 0;
}



int proc_pkg_from_client(void* data, int len, fdsession_t* fdsess)
{
    //通过服务名连接到msgverif服务器
    if(msgverif_fd == -1){
        //msg_verif的服务名是 msgverif 服务ID赋0 connect_to_service 自行挑选可用的msgverif服务
        msgverif_fd=connect_to_service("msgverif",1,64*1024,1);
        //连接失败
        if(msgverif_fd == -1){
       //     printf("error\n");
          return send_pkg_to_client(fdsess,"system error!!\n",15);
        }
    }
    //检查是否为客户端分配了内存
    //如果没有分配内存 就要调用 alloc_client 函数为其分配内存
    client_t *cli = find_client_by_fd(fdsess->fd);
    if(cli==NULL)
    {
       cli=alloc_client(fdsess);
    }
    //在bench.conf 里限制了最大接受长度为4000个字节
    char buf[4096];
    msgverif_pkg_t *pkg=(void*)buf;
    //客户端发送过来的数据长度加上包头长度就是整个包的长度
    pkg->len =len+sizeof(msgverif_pkg_t);
    pkg->id = cli->id;
    memcpy(pkg->buf,data,len);
    //把数据转发给msgverif服务器
    return net_send(msgverif_fd,pkg,pkg->len);
}

void proc_pkg_from_serv(int fd, void* data, int len)
{
    if(fd == msgverif_fd){
     msgverif_pkg_t *pkg = data;
     //根据客户端ID找到客户端 然后给客户端返回数据
     client_t *cli =find_client_by_id(pkg->id);
     if(cli){
        send_pkg_to_client(cli->fdsess,pkg->buf,pkg->len -sizeof(msgverif_pkg_t));
     }
    
    }
}

void on_client_conn_closed(int fd)
{
    //客户端关闭 清除为该连接分配的内存
    client_t *cli = find_client_by_id(fd);
    if(cli){
      dealloc_client(cli);
    }
}

void on_fd_closed(int fd)
{
    if(fd == msgverif_fd){
      //msgverif服务器关闭了和echo服务器的连接
      msgverif_fd =-1;
    }
}


static client_t *alloc_client(fdsession_t *fdsess){

    static uint32_t id =1;
    client_t *cli = &(clients[fdsess->fd]);
    cli->fdsess = fdsess;
    cli->id = id++;
    if(id == 0){ //确保id不为0
       ++id;
    }
    return cli;
}
static void dealloc_client(client_t*cli){
   cli->fdsess =0;
   cli->id =0;
}

static client_t *find_client_by_id(uint32_t id){
    //为简化代码 这里使用了最简单的暴力便利查找法
    int i;
    for(i=0;i!=client_max_num;++i){
      client_t * cli=&(clients[i]);
      if(cli->id == id){
        return cli;
      }
    }
   return 0;
}

static client_t* find_client_by_fd(int fd){

int i;
  for(i=0;i!=client_max_num;++i)
  {
       client_t * cli=&(clients[i]);
        if( cli->fdsess && cli->fdsess->fd  == fd){
          return cli;
        }
  }
  return 0;
}

