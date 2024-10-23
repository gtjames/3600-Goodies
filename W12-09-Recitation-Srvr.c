// compile: gcc rec09svr.c -o rec09svr
// usage  : ./rec09svr port

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
	int listenfd = 0, connfd = 0, cli_size, portno;

	struct sockaddr_in serv_addr, cli_addr;

	char sendBuff[1025];  
 
	if ((listenfd = socket(  ?  )) == -1)
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}

	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;    
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	portno = atoi(argv[1]);
	serv_addr.sin_port = htons(portno);    

	if (bind(  ?  ) == -1)
	{
		printf("bind error\n");
		exit(EXIT_FAILURE);
	}


	if (listen(  ?  ) == -1)
	{
		printf("listen error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		cli_size = sizeof(cli_addr);
		if ((connfd = accept(  ?  )) == -1)
		{
			printf("accept error\n");
			exit(EXIT_FAILURE);
		}

		strcpy(sendBuff, "Server Message: SUCCESS\n");
		write(connfd, sendBuff, strlen(sendBuff));

		close(connfd);    
		sleep(1);
	} 
 
	return 0;
}


