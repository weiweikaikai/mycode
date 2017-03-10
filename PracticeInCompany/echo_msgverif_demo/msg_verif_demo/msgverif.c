#include <stdint.h>

#include <async_serv/net_if.h>

#pragma pack(1)

// 本结构体用于接收echo服务器发过来的包
typedef struct msgverif_pkg {
	uint32_t	len;   // 整个包的长度
	uint32_t	id;    // 唯一ID，用于在msgverif服务器返回时找到原来的客户端
	char		buf[]; // 客户端发送过来的数据
} msgverif_pkg_t;

#pragma pack()

int	get_pkg_len(int fd, const void* pkg, int pkglen, int isparent)
{
	if (isparent) {
		// 可用数据不足4个字节，不能解析出报文长度
		if (pkglen < 4) {
			return 0;
		}

		const msgverif_pkg_t* msgpkg = pkg;
		// 如果报文中的len小于报文最小长度，则说明是个非法报文
		if (msgpkg->len <= sizeof(msgverif_pkg_t)) {
			return -1;
		}

		return (int)msgpkg->len;
	}

	return 0;
}

int proc_pkg_from_client(void* data, int len, fdsession_t* fdsess)
{
	   int i=0;
       char *str = (char*)data;
       for(i=0;i<len;++i)
       {
          if(str[i] == 'k')
          {
               return send_pkg_to_client(fdsess,(void*)"h",11 );
          }
       }
    return send_pkg_to_client(fdsess, data, len);
}

void proc_pkg_from_serv(int fd, void* data, int len)
{
}

void on_client_conn_closed(int fd)
{
}

void on_fd_closed(int fd)
{
}
