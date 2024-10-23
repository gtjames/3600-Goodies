// compile: gcc rec09cli.c -o rec09cli
// usage  : ./rec09cli port

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
 
int main(int argc, char *argv[])
{
	int sockfd = 0, n = 0, portno;
	char recvBuff[1025];
	struct sockaddr_in serv_addr;
 
	memset(recvBuff, '0', sizeof(recvBuff));
	if ((sockfd = socket(  ?  )) < 0)
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}
 
	serv_addr.sin_family = AF_INET;
	portno = atoi(argv[1]);
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
	if (connect(  ?  ) < 0)
	{
		printf("connect error\n");
		exit(EXIT_FAILURE);
	}
 
	while ((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
	{
		recvBuff[n] = 0;
		if (fputs(recvBuff, stdout) == EOF)
		{
			printf("fputs error\n");
		}
	}
 
	if (n < 0)
	{
		printf("read error\n");
	}
 
	return 0;
}


