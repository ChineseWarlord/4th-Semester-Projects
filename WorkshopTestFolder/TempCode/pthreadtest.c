#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* func(void* p) {
   printf("From the function, the thread id = %d\n", pthread_self()); //get current thread id
      pthread_exit(NULL);
   return NULL;
}

void* generatedata(void* arg) {
    srand(time(NULL));

    float data = ((float)rand()/(float)RAND_MAX);
    float *result = (float*)malloc(data*sizeof(float));
    *result = data;
    printf("Data: %f\n", data);

    return result;
}

int main() {
    float *result;
    float shit;
    pthread_t thread1, thread2; // declare thread
    for (int i = 0; i < 1; i++) {
        pthread_create(&thread1, NULL, generatedata, NULL);
        printf("From the main function, the thread id = %d\n", thread1);
        pthread_join(thread1, (void**)&result); //join with main thread
        shit = *result;
        printf("Result is: %f\n", shit);
        free(result);

        pthread_create(&thread2, NULL, generatedata, NULL);
        printf("From the main function, the thread id = %d\n", thread2);
        pthread_join(thread2, (void**)&result); //join with main thread
;       shit = *result;
        printf("Result is: %f\n", shit);
        free(result);

        }

        pthread_exit(NULL);
        return 0;
        }