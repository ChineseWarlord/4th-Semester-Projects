#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "TempSensorStub.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXBUF 64

int main()
{ 
  char message[MAXBUF];
  struct sockaddr_in Client;
  int sockfd, len = sizeof(Client);
  

  pthread_t T1;
  float *result;
  int Timer = 0; //Antal sek der skal genereres data
  int Time = 0;
  int sleep = usleep(100000);

  sockfd = socket(PF_INET, SOCK_DGRAM, 0); // create a UDP socket
  
  if(sockfd == -1) {
    if (sockfd == -1){
        perror("Failed to create socket");
        exit(0);
    }
  }
  
  /* configure settings to communicate with remote UDP server */
  Client.sin_family = AF_INET;
  Client.sin_port = htons(8888); // server port
  Client.sin_addr.s_addr = inet_addr("127.0.0.1"); // local-host

  printf("How many seconds should the program run?\n");
  scanf("%d", &Time);
  printf("You inserted: %d seconds \n\n", Time);
  sleep;

  while(Timer < Time){
    Timer++;
    pthread_create(&T1, NULL, TempGen, NULL);
    pthread_join(T1, (void**)&result);
    printf("Main result: %0.01f\n", *result); 
    printf("Main Address: %p\n", result); 
    gcvt(*result, 3, message);
    printf("Buffer is: %s\n", message);
    printf("\n");
    sendto(sockfd, message, MAXBUF, 0, (struct sockaddr *)&Client, len); //send the data to server
    free(result);
    sleep;
    }

  close(sockfd); //close socket file-descriptor
  
  return 0;
}