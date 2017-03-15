#include"msg.pb.h"
#include<iostream>
#include<string>
using namespace std;


int main(int argc,char *argv[])
{
    demo::msg writer;
    writer.set_msgtype(1);
    writer.set_msginfo("i am weeks");
    writer.set_msgfrom("127.0.0.1");

     //C++string序列化和序列化API   
   
    //客户端格式化信息
    string in_data;
    writer.SerializeToString(&in_data); 
    //下面用一个临时的string 表示在网络中进行传输的过程
    //真是的过程中你可以借助相应的网络框架对数据进行传输
    //客户端将数据放到网络上   
    string tmp=in_data;



    //服务端从网络上拿数据 
    string out_data=tmp;
    //服务端反格式化信息
    demo::msg reader;
    reader.ParseFromString(out_data);
    cout<<"msg_type: "<<reader.msgtype()<<endl;
    cout<<"msg_info: "<<reader.msginfo()<<endl;
    cout<<"msg_from: "<<reader.msgfrom()<<endl;

    return 0;
}
