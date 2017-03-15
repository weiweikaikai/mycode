#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <libtaomee/inet/tcp.h>
#include<msg.pb.h>


int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage: %s ipaddr port\n", argv[0]);
		return -1;
	}

	int sockfd = safe_tcp_connect(argv[1], atoi(argv[2]), 5, 0);
	if (sockfd == -1) {
		perror("connect: ");
		return -1;
	}
   wk::msg reader;
   reader.set_msgtype(1);
   reader.set_msginfo("i am ");
   reader.set_msgfrom("weeks");
	char buf[256];
    read(sockfd, buf, strlen(buf) + 1);
    reader.ParseFromArray(buf,256);
    cout<<"msg_type: "<<reader.msgtype()<<endl;
    cout<<"msg_info: "<<reader.msginfo()<<endl;
    cout<<"msg_from: "<<reader.msgfrom()<<endl;

	return 0;
}
