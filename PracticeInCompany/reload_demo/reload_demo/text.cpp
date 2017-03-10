/*************************************************************************
	> File Name: text.cpp
	> Author: weeks
	> Mail: weeks@taomee.com
	> compiler: gcc4.3.2
	> platform: linux
	> Created Time: Fri 17 Feb 2017 10:31:45 AM CST
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
#include<async_serv/net_if.h>
 
extern vector<int*> ivec;

extern "C" int init_service(int isparent)
{
  if(!isparent)
  {
     for(int i=0;i != 10;++i)
     {
        ivec.push_back(new int(i));
     }
  }
  return 0;
}

extern "C" int reload_gloabl_data()
{
     cout<<"ivec size"<<ivec.size()<<endl;
     for(vector<int*>::iterator it=ivec.begin();it != ivec.end();++it)
     {
        cout<<**it<<endl;
     }
     return 0;
}

extern "C" int get_pkg_len(int fd,const void *pkg,int pkglen,int isparent)
{
   return 0;
}


extern "C" int proc_pkg_from_client(void*data,int len,fdsession_t *fdsess)
{
    return 0;
}


extern "C" void proc_pkg_from_serv(int fd,void *data,int len)
{}
extern "C"void on_client_conn_closed(int fd)
{}
extern "C"void on_fd_closed(int fd)
{}



