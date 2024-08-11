#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * run();

int main(void)
{
    int i;
    pthread_t tid;
    
    printf("Demonstration of threads.\n");
    pthread_create(&tid, NULL, run, 0);

    for (i = 0; i < 5; i++)
    {
        printf("This is inside main.\n");
        sleep(1);
    }
}

void * run()
{
    for (int i = 0; i < 5; i++)
    {
        printf("This is inside thread.\n");
        sleep(1);
    }
    pthread_exit(0);
}