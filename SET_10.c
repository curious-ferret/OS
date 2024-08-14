//Reader-Writer
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t mutex, rw_mutex;
int data = 0, rc = 0;

void * reader(void * arg)
{
    int f = ((int) arg);
    //the below code can be used to safely typecast a pointer to an integer and void warnings
    //int f = (intptr_t)arg;

    sem_wait(&mutex);
    rc++;
    if (rc == 1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);

    printf("Data read by reader %d is %d\n", f, data);
    sleep(1);

    sem_wait(&mutex);
    rc--;
    if (rc == 0)
        sem_post(&rw_mutex);
    sem_post(&mutex);
}

void * writer(void * arg)
{
    int f = ((int) arg);
    sem_wait(&rw_mutex);
    data++;
    printf("Data written by writer %d is %d\n", f, data);
    sleep(1);
    sem_post(&rw_mutex);
}

int main(void)
{
    int i, b;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    for (i = 0; i <=2; i++)
    {
        pthread_create(&wtid[i], NULL, writer, (void *) i);
        pthread_create(&rtid[i], NULL, reader, (void *) i);
    }

    for (i = 0; i <=2; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    return 0;
}
