#include "yespower.h"
#include <stdio.h>
#include <string.h>
#include "hextools.h"

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 80


int yespower_hash(const char *input, char *output);




int main (int argc, char *argv[]) {

  int port = atoi(argv[1]);

  int server_fd, client_fd, err;
  struct sockaddr_in server, client;
  char buf[BUFFER_SIZE];
  char dis[32];
  char out[256];

  server_fd = socket(AF_INET, SOCK_STREAM, 0);

  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  int opt_val = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val);

  err = bind(server_fd, (struct sockaddr *) &server, sizeof(server));

  err = listen(server_fd, 128);

  printf("Server is listening on %d\n", port);

  while (1) {
    socklen_t client_len = sizeof(client);
    client_fd = accept(server_fd, (struct sockaddr *) &client, &client_len);


    while (1) {
      int read = recv(client_fd, buf, BUFFER_SIZE, 0);
      //printf ("%d\n", read);

      if (!read) break; // done reading

	//printf("%s\n", argv[1]);
	//char * temp = hex2bin(buf);
	//char * out = malloc(256);
	//char * dis = malloc(33);
	//out = bin2hex(buf,80);
	//printf("%s\n", out);

	err=yespower_hash(buf,dis);
	//out = bin2hex(dis,32);
	//printf("%s\n", out);

      err = send(client_fd, dis, 32, 0);
//      free(dis);
    }
  }

  return 0;
}

