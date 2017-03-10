#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <libtaomee/inet/tcp.h>

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

	char buf[4096];
	while (fgets(buf, 4096, stdin)) {
		write(sockfd, buf, strlen(buf) + 1);
		read(sockfd, buf, 4096);
		printf("%s", buf);
	}

	return 0;
}
