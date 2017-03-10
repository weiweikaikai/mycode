#include"msg.pb.h"
#include<iostream>
#include<string>
using namespace std;


int main(int argc,char *argv[])
{
    demo::msg test;
    test.set_msgtype(1);
    test.set_msginfo("i am weeks");
    test.set_msgfrom("127.0.0.1");
     
    //格式化信息
    string in_data;
    test.SerializeToString(&in_data);
    cout<<"format: "<<in_data<<endl;

    //反格式化
    demo::msg msg_encoding;
    msg_encoding.ParseFromString(in_data);
    cout<<"msg_type: "<<msg_encoding.msgtype()<<endl;
    cout<<"msg_info: "<<msg_encoding.msginfo()<<endl;
    cout<<"msg_from: "<<msg_encoding.msgfrom()<<endl;

     return 0;
}
