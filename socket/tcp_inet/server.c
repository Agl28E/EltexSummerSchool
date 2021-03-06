#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "erproc.h"

int main() 
{
	int server = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET;
	adr.sin_port = htons(7777);
	

	Bind(server, (struct sockaddr *) &adr, sizeof adr);		
	Listen(server, 5);
	socklen_t adrlen = sizeof adr;
	int fd = Accept(server, (struct sockaddr *) &adr, &adrlen);
	ssize_t nread;
	char buf[256];
	nread = recv(fd, buf, 256, 0); 
	send(fd, buf, nread, 0);
	sleep(1);
	
	close(fd);
	close(server);


	return 0;
}
