#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

const int LISTEN_PORT_NUMER = 7000;
const int MAX_STRING_SIZE = 255;

int main()
{
  int sockfd, newsockfd;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  char incoming_message[MAX_STRING_SIZE], temp_string[MAX_STRING_SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    printf("Error building Socket FD");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(LISTEN_PORT_NUMER);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("Error in Binding");
    exit(1);
  }

  if (listen(sockfd, 2) < 0)
  {
    printf("Error listening");
    exit (1);
  };

  while(1)
  {
    clilen = sizeof(cli_addr);
    printf("Ready to accept connections\n");
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen );

    if (newsockfd < 0)
    {
      printf("Error accepting connection");
      exit(1);
    }

    read(newsockfd, incoming_message, sizeof(incoming_message));
    sprintf(temp_string, "Hello %s, you said %s, haha", inet_ntoa(cli_addr.sin_addr), incoming_message);
    if (write(newsockfd, temp_string, sizeof(incoming_message)) < 0)
    {
      printf("Error writing out");
      exit(1);
    }
    close (newsockfd);
  }
  close(sockfd);
  return 0;
}
