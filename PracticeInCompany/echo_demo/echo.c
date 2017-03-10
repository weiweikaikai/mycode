#include <async_serv/net_if.h>

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
	}

	return 0;
}

int proc_pkg_from_client(void* data, int len, fdsession_t* fdsess)
{
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
