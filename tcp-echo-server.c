#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

static void die(const char* s) { perror(s); exit(1); }

int main(int argc, char **argv)
{
	if(argc != 2) {
		fprintf(stderr, "usage: %s <server-port>\n", argv[0]);
		exit(1);
	}
	
	unsigned short port = atoi(argv[1]);
	
	//creating a listening socket
	int serversock;
	const int con_q_size = 5;
	const int buf_size = 10;
	if ((serversock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		die("socket failed");

	//construct local address structure
	struct socketaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);

	//binding to local addr
	if(bind(servsock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
		die("bind failed");
	
	//listening to incoming connections
	if(listen(servsock, con_q_size) < 0)
		die("listen failed");

	int r;
	char buf[buf_size];
	
	int clntsock;
	socklen_t clntlen;
	struct sockaddr_in clntaddr;
	
	while(1){
		fprintf(stderr, "waiting for client");
	
		clntlen = sizeof(clntaddr);
	
		if((clntsock = accept(servsock,
					(struct sockaddr *) &clntaddr, &clntlen)) < 0)
			die("accept failed");
		
		fprintf(stderr, "client ip: %s\n", inet_ntoa(clntaddr.sin_addr));
		
		while((r = recv(clntsock, buf, sizeof(buf), 0)) > 0){
			*buf = touper(*buf);
			if(send(clntsock, buf, r, 0) != r){
				fprintf(stderr, "ERR: send failed\n");
				break;
			}
		}

		if(r < 0){
			fprintf(stderr, "ERR: recv failed\n");
		}

		closed(clntsock);
	}
}
	
	int clntsock;
	socklen_t clntlen;
	struct sockaddr_in clntaddr;
	
	while(1){
		fprintf(stderr, "waiting for client");
	
		clntlen = sizeof(clntaddr);
	
		if((clntsock = accept(servsock,
					(struct sockaddr *) &clntaddr, &clntlen)) < 0)
			die("accept failed");
		
		fprintf(stderr, "client ip: %s\n", inet_ntoa(clntaddr.sin_addr));
		
		while((r = recv(clntsock, buf, sizeof(buf), 0)) > 0){
			*buf = touper(*buf);
			if(send(clntsock, buf, r, 0) != r){
				fprintf(stderr, "ERR: send failed\n");
				break;
			}
		}

		if(r < 0){
			fprintf(stderr, "ERR: recv failed\n");
		}

		closed(clntsock);
	}
}
	
	int clntsock;
	socklen_t clntlen;
	struct sockaddr_in clntaddr;
	
	while(1){
		fprintf(stderr, "waiting for client");
	
		clntlen = sizeof(clntaddr);
	
		if((clntsock = accept(servsock,
					(struct sockaddr *) &clntaddr, &clntlen)) < 0)
			die("accept failed");
		
		fprintf(stderr, "client ip: %s\n", inet_ntoa(clntaddr.sin_addr));
		
		while((r = recv(clntsock, buf, sizeof(buf), 0)) > 0){
			*buf = touper(*buf);
			if(send(clntsock, buf, r, 0) != r){
				fprintf(stderr, "ERR: send failed\n");
				break;
			}
		}

		if(r < 0){
			fprintf(stderr, "ERR: recv failed\n");
		}

		closed(clntsock);
	}
}
	
	int clntsock;
	socklen_t clntlen;
	struct sockaddr_in clntaddr;
	
	while(1){
		fprintf(stderr, "waiting for client");
	
		clntlen = sizeof(clntaddr);
	
		if((clntsock = accept(servsock,
					(struct sockaddr *) &clntaddr, &clntlen)) < 0)
			die("accept failed");
		
		fprintf(stderr, "client ip: %s\n", inet_ntoa(clntaddr.sin_addr));
		
		while((r = recv(clntsock, buf, sizeof(buf), 0)) > 0){
			*buf = touper(*buf);
			if(send(clntsock, buf, r, 0) != r){
				fprintf(stderr, "ERR: send failed\n");
				break;
			}
		}

		if(r < 0){
			fprintf(stderr, "ERR: recv failed\n");
		}

		closed(clntsock);
	}
}
