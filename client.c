#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

union sock
{
  struct     sockaddr s;
  struct  sockaddr_in i;
} sock;

int main(int argc, char *argv[])
{
  int sockfd, portno;
  char buffer[255];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc < 3)
  {
    printf("Please provide correct arguments");
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  exit(1);

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(1);
  }
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);
  bcopy(&serv_addr, &sock.i, sizeof(struct sockaddr_in));
  if ( connect(sockfd, &sock.s, sizeof(struct sockaddr)) < 0)
  {
    printf("Error with connection");
    exit(1);
  }
  int msg_cnt=0;
  while (1) {
	msg_cnt++;
	printf("Type in msg %d:\n", msg_cnt);
	scanf("%s", buffer);
	printf("Message typed in is: %s \n", buffer);
	write(sockfd, buffer, sizeof(buffer));
	read(sockfd, buffer, sizeof(buffer));
	printf(">>>>>> SERVER: %s\n", buffer);
  }
  close(sockfd);
  return 0;
}
