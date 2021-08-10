#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "erproc.h"

int main()
{
	int fd = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET;
	adr.sin_port = htons(7777);
	inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
	connect(fd, (struct sockaddr *) &adr, sizeof adr);
	send(fd, "Hello\n", 6, 0);
	char buf[256];
	ssize_t nread;
	nread = recv(fd, buf, 256, 0);
	send(fd, buf, nread, 0);
	close(fd);
	return 0;
}
