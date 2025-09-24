#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>



#define MAX_MSG_SIZE 4096
#define MAX_CLIENTS 1024

typedef struct s_client
{
	int id;
	char msg[MAX_MSG_SIZE];
} t_client;

//we define public variables here
t_client clients[MAX_CLIENTS]; // here we define an array of clients
int next_id = 0; // here we define the next id to be assigned to a new client
int maxfd = 0; // here we define the maximum file descriptor

fd_set read_set, write_set, current;





int main(int ac, char **av) {
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(8081); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0) {
		printf("cannot listen\n"); 
		exit(0); 
	}
	len = sizeof(cli);
	connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n");
}

// Have to prepare for 42ecole examrank06, I will basically be given the main and have to transform it to mini_serv, help me break down the problem and tackle how I will do it step by step. I will ofc start off by removing things I dont need from the main, so tell me what to remove and what to keep. and then we can start adding stuff

// mini_serv file is basically gospel. It passed the exam so anything within it is allowed and OKAY to do.