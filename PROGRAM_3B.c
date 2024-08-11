#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * run1();
void * run2();
void * run3();
void * run4();

int main(void)
{
    int i;
    pthread_t tid1, tid2, tid3, tid4;
    
    printf("Demonstration of multiple thread operations.\n");
    
    //Thread1
    pthread_create(&tid1, NULL, run1, 0);
    //Thread2
    pthread_create(&tid2, NULL, run2, 0);
    //Thread3
    pthread_create(&tid3, NULL, run3, 0);
    //Thread4
    pthread_create(&tid4, NULL, run4, 0);

    pthread_join(tid1, 0);
    pthread_join(tid2, 0);
    pthread_join(tid3, 0);
    pthread_join(tid4, 0);

    for (i = 0; i < 5; i++)
    {
        printf("This is inside main.\n");
        sleep(1);
    }
}

void * run1()
{
    for (int i = 0; i < 5; i++)
    {
        printf("This is inside thread 1.\n");
        sleep(2);
    }
    pthread_exit(0);
}
void * run2()
{
    for (int i = 0; i < 5; i++)
    {
        printf("This is inside thread 2.\n");
        sleep(2);
    }
    pthread_exit(0);
}
void * run3()
{
    for (int i = 0; i < 5; i++)
    {
        printf("This is inside thread 3.\n");
        sleep(2);
    }
    pthread_exit(0);
}
void * run4()
{
    for (int i = 0; i < 5; i++)
    {
        printf("This is inside thread 4.\n");
        sleep(2);
    }
    pthread_exit(0);
}