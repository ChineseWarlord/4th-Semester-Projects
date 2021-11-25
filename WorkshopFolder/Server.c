#include<stdio.h>	//printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <pthread.h>
#include <time.h>

char curr_time[21];
char* format_time(){ //Funktion til at formatere tid: [dd/mm/yy hh:mm:ss]
    time_t rawtime;
    struct tm * timeinfo;time ( &rawtime );
    timeinfo = localtime (&rawtime);
    sprintf(curr_time, "[%d %d %d %d:%d:%d]", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return curr_time;
}

void* WriteFile(void* arg){ //Funktion som skriver ind i fil
    FILE *fp;   //Deklarerer filpointer
	char *data = arg;

    fp = fopen("Data.txt","a"); //Opretter dokumentet "Data.txt" og åbner dokumentet i en "append-mode"

    fprintf(fp,"%s %s C\n", format_time(), data); //Skriver data'en ind i filen
    fclose(fp); //Lukker filen
    pthread_exit(NULL); // Vi returner intet så vi kalder denne funktion
}

#define MAXBUF 1024	//Max length of buffer
#define PORT 8888	//The port on which to listen for incoming data

void die(char *s)
{
	perror(s);
	exit(1);
}

int main(void)
{
	pthread_t T1, T2; 
	struct sockaddr_in si_me, si_other;
	int sockfd, i, slen = sizeof(si_other) , recv_len;
	char buf[MAXBUF];
	
	//create a UDP socket
	if ((sockfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}
	
	// zero out the structure
	memset((char *) &si_me, 0, sizeof(si_me));
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//bind socket to port
	if( bind(sockfd , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
	{
		die("bind");
	}
	
	//keep listening for data
	while(1)
	{
		printf("Waiting for data...\n");
		fflush(stdout);
        memset(buf, '\0', MAXBUF);
		
		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(sockfd, buf, MAXBUF, 0, (struct sockaddr *) &si_other, &slen)) == -1)
		{
			die("recvfrom()");
		}
		
		//print details of the client/peer and the data received
		printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		printf("Data: %s\n" , buf);

		pthread_create(&T2, NULL, WriteFile, buf); //Opretter en tråd og eksekverer funktionen 'WriteFile' som tager argumentet "Reference til variablen Avg (&Avg)"
        pthread_join(T2, NULL); //Vent til thread T2 er færdig med at eksekvere funktionen, returner ingenting.
		
	}
	close(sockfd);
	return 0;
}