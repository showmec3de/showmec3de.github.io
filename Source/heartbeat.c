#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int init_data(char *buff){
	FILE *fp;
	memset(buff,0,64);
	fp = fopen("/tmp/serverDATA","r");
	fscanf(fp,"%s",buff);
	fclose(fp); 
}

int main()  
{  
	sleep(3);
	char data[64];
	init_data(data);
	char* server_addr = strtok(data,"!!!!");
	char* server_port = strtok(NULL,"!!!!");
	int server_PORT = atoi(server_port);

	int s;
	char buff[2048];
	struct sockaddr_in my_addr;
	int sin_size;
	memset (&my_addr, 0, sizeof (my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_port = htons (8888);
	s = socket (PF_INET, SOCK_STREAM, 0);
	bind (s, (struct sockaddr *) &my_addr, sizeof (struct sockaddr));
	listen (s, 5);
	sin_size = sizeof (struct sockaddr_in);

	int soc;
	struct sockaddr_in server;
	char bufff[2048];
	memset (&server, 0, sizeof (server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr (server_addr);
	server.sin_port = htons (server_PORT);
	soc = socket (PF_INET, SOCK_STREAM, 0);
	
	int fd;
	struct sockaddr_in remote_addr;
		
	while (1)
	{
		fd = accept (s, (struct sockaddr *) &remote_addr, &sin_size);
		int len = recv (fd, buff, 2048, 0);
		if (len > 0)
		{
			connect (soc, (struct sockaddr *) &server, sizeof (struct sockaddr));
			send (soc, buff, len, 0);
			int length = recv (soc, bufff, 2048, 0);
			if (length > 0)
			{
				send (fd, bufff, length, 0);
			}
		}
		close (fd);	
		close (soc);
	}
	
	close (fd);
	close (s);
	close (soc);
	return 0;
}  

