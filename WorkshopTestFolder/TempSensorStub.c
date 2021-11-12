#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* TempGen(void* arg){
    int Count = 10; //Antal målinger
    float Avg[Count], sum, n;
    float avg = *(float*)arg;

    srand((unsigned int)time(NULL));

    for(int i = 0; i < Count; i++){
        n=((float)rand()/(float)RAND_MAX)*(50.0);
        Avg[i] = n;
        sum += Avg[i];
        //printf("Temp: %f\n", Avg[i]);
        int sleep = usleep(1*100000); //Vent 1 sekund
    }
    avg = sum / Count;
    printf("Avg is: %0.1f\n", avg);

    float *result = malloc(sizeof(result));
    *result = avg;

    return result;
}
