#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int boolean = 0;

void parse(char *buffer, char *args, char *text)
{
	int fd;
	int i=5;
	
	while(buffer[i] != ' '){
        	args[i-5] = buffer[i];
        	i++;
	}
	 args[5-i] = 0;

 	bzero(text,sizeof(text));

 	if(args[0] != 0){
        	fd = open(args, O_RDONLY);
        }
	if(fd < 0){
                boolean = 1;
        }
        i = read(fd, text, 1024);
}

int main(int argc, char* argv[]){

	int sd, cd, i, port, pid;
	unsigned int addrlen;
	struct sockaddr_in saddr, caddr;
	char buffer[1024];
	char argsv[1024];
 	char *header;
 	char text[1024];

	port=atoi(argv[1]);

	if (argc != 2){
		printf("Usage: Need to enter on port number\n");
		exit(0);
	}

	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = 0;
	saddr.sin_port = htons(port);

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0){
		perror("socket");
		exit(-1);
	}

	i = bind(sd, (struct sockaddr *) &saddr, sizeof(saddr));
	if(i < 0){
		perror("bind");
		exit(-1);
	}
	
	if(listen(sd, 5) < 0){
		perror("listen");
		exit(-1);
	}

	while((cd = accept(sd, (struct sockaddr *) &caddr, &addrlen)) > 0){

		addrlen = 0;
		pid = fork();

		if (pid == 0){
			while ((i=read(cd, buffer, 1024)) < 0){
				
				buffer[i] = 0;
				parse(buffer,argsv,text);
				if(boolean){
                         	       header = "HTTP/1.1 404 Not Found\n\n";
                        	}
                        	else{
                		       header = "HTTP/1.1 200 OK\n\n";
                        	}	

				if (i > 0){
					i=write(cd, header, i);
                                	i=write(cd, text, i);
				}
				printf("buffer: %s\n",buffer);
                        	printf("header:%s text:%s\n",header,text);
			}
		}
		else{
			close(cd);
		}
	}
	exit(0);
}
