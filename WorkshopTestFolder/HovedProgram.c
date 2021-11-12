#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "TempSensorStub.h"

char curr_time[21];

char* format_time(){
    time_t rawtime;
    struct tm * timeinfo;time ( &rawtime );
    timeinfo = localtime (&rawtime);
    sprintf(curr_time, "[%d %d %d %d:%d:%d]", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return curr_time;
}

void* WriteFile(void* arg){
    FILE *fp;
    float data;

    fp = fopen("Data.txt","a");
    data= *(float*)arg;
    fprintf(fp,"%s %0.1f C\n", format_time(), data);
    fclose(fp);
    return 0;
}

int main() {
    pthread_t T1, T2;
    float Avg, *result;
    int Timer = 5; //Antal sek der skal genereres data
    
    for (int i = 0; i < Timer; i++){
        pthread_create(&T1, NULL, TempGen, &Avg);
        pthread_join(T1, (void **)&result);
        Avg = *result;
        pthread_create(&T2, NULL, WriteFile, &Avg);
        free(result);
        int sleep = usleep(1000000);
    }
    pthread_exit(NULL);
    exit(0);
}