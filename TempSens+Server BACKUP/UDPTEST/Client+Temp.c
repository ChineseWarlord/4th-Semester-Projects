#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <pthread.h>
#include <time.h>
#include "TempSensor.h"

#define MAXBUF 1024

int main()
{ 
    int sockfd, len, i;
    char buf[MAXBUF];
    char message[MAXBUF];
    struct sockaddr_in udp_server_addr;
    socklen_t addr_size;

    pthread_t T1, T2; //Deklarerer variabel T1/T2, af typen pthread_t
    float *result;
    int Timer = 5; //Antal sek der skal genereres data

    sockfd = socket(PF_INET, SOCK_DGRAM, 0); // create a UDP socket
    if(sockfd<=0) { 
        printf("socket error !\n"); return 0;
        }  
    /* configure settings to communicate with remote UDP server */
    udp_server_addr.sin_family = AF_INET;
    udp_server_addr.sin_port = htons(8888); // server port
    udp_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // local-host
    memset(udp_server_addr.sin_zero, '\0', sizeof udp_server_addr.sin_zero);  
    addr_size = sizeof udp_server_addr;
    memset(buf, 0xab, MAXBUF); // set the entire buffer with 0xab (i.e 1010 1011 binary)
    for (int i = 0; i < Timer; i++){
        pthread_create(&T1, NULL, TempGen, NULL);
        pthread_join(T1, (void**)&result);
        printf("Main result: %0.01f\n", *result); 
        printf("Main Address: %p\n", result); 
        
        gcvt(*result, 1, message);
        sendto(sockfd, message, MAXBUF, 0, (struct sockaddr *)&udp_server_addr, addr_size); //send the data to server
    
        len = recvfrom(sockfd, buf, MAXBUF, 0, NULL, NULL); // receive data from server
        printf("Received from server: %d bytes\n", len); for(i=0;i<len;i++) { printf("%02x ", buf[i]); } printf("\n"); //print received data dump
        printf("\n");
        free(result);
        int sleep = usleep(1000000);
    }

  /*while(1){
      printf("Enter message: ");
      fgets(message, MAXBUF, stdin);

      sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&udp_server_addr, addr_size); //send the data to server
      
      len = recvfrom(sockfd, buf, MAXBUF, 0, NULL, NULL); // receive data from server

      printf("Received from server: %d bytes\n", len); for(i=0;i<len;i++) { printf("%02x ", buf[i]); } printf("\n"); //print received data dump
      printf("\n");

  }*/

  close(sockfd); //close socket file-descriptor
  
  return 0;
}