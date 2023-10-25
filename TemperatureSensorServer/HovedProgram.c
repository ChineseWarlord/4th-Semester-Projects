//HovedProgram.c
//https://github.com/ChineseWarlord/OS-Workshop.git
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "TempSensorStub.h"

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
    float data;

    fp = fopen("Data.txt","a"); //Opretter dokumentet "Data.txt" og åbner dokumentet i en "append-mode"
    data = *(float*)arg;    //Sætter argumentet til at være lig med data.   - vi "caster" til float pointer og derefter dereference den
    fprintf(fp,"%s %0.1f C\n", format_time(), data); //Skriver data'en ind i filen
    fclose(fp); //Lukker filen
    pthread_exit(NULL); // Vi returner intet så vi kalder denne funktion
}

int main() {
    pthread_t T1, T2; //Deklarerer variabel T1/T2, af typen pthread_t
    float *result;
    int Timer = 5; //Antal sek der skal genereres data

    for (int i = 0; i < Timer; i++){ //Hvor lang tid programmet skal køre
        pthread_create(&T1, NULL, TempGen, NULL); //Opretter en tråd, der eksekverer funktionen 'TempGen'
        pthread_join(T1, (void**)&result); //Returnerer pointeren altså returnerer en addresse.
        printf("Main result: %0.01f\n", *result); //Tjekker om resultatet stemmer overens som i TempGenStub
        printf("Main Address: %p\n", result); //Tjekker om addressen stemmer overens som i TempGenStub

        pthread_create(&T2, NULL, WriteFile, &*result); //Opretter en tråd og eksekverer funktionen 'WriteFile' som tager argumentet "Reference til variablen Avg (&Avg)"
        pthread_join(T2, NULL); //Vent til thread T2 er færdig med at eksekvere funktionen, returner ingenting.
        free(result);
        int sleep = usleep(1000000);
    }
    
    return 0;
}

