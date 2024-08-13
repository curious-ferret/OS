//a). Program to simulate solution to Producer-Consumer problem.
#include <stdio.h>
#include <stdlib.h>

int full = 0, empty = 3, mutex = 1;

int main(void)
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    printf("\n1.Produce\n2.consume\n3.exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch(n)
        {
            case 1: if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full!\n");
            break;

            case 2: if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty!\n");
            break;

            case 3: exit(0);
        }
    }
    return 0;
}

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("Producer produces item number: %d.\n", full);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    empty = signal(empty);
    printf("Consumer consumes item number: %d.\n", full);
    full = wait(full);
    mutex = signal(mutex);
<<<<<<< HEAD
}
=======
}
>>>>>>> 5225172a92c92f40f9e818ca17e6d1820b278af8
