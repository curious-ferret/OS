//Dining Philosopher
#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
# define N 5
# define THINKING 0 
# define HUNGRY 1 
# define EATING 2
# define LEFT (phnum + N - 1) % N 
# define RIGHT (phnum + 1) % N 
int phnum;
int state[N];
int phil[N] = {0, 1, 2, 3, 4}; 
sem_t mutex;
sem_t s[N];

void test(int phnum) {
    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) { 
        state[phnum] = EATING;
        sleep(2);
        printf("phil %d takes fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1); 
        printf("phil %d is eating\n", phnum + 1);
        sem_post(&s[phnum]);
    }
}

void takefork(int phnum) {
    sem_wait(&mutex); 
    state[phnum] = HUNGRY;
    printf("phil %d is hungry\n", phnum + 1); 
    test(phnum);
    sem_post(&mutex); 
    sem_wait(&s[phnum]); 
    sleep(1);
}

void putfork(int phnum) {
    sem_wait(&mutex); 
    state[phnum] = THINKING;
    printf("phil %d putsdown fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1); 
    printf("phil %d is in thinking state\n", phnum + 1);
    test(LEFT); 
    test(RIGHT); 
    sem_post(&mutex);
}

void * philosopher(void * num) { 
    while(1) {
        int * i = num; 
        sleep(1); 
        takefork(* i); 
        sleep(1); 
        putfork(* i);
    }
}

int main(void) {
    int i;
    pthread_t tid[N]; 

    sem_init(&mutex, 0, 1); 
    for (i = 0; i < N; i++)
        sem_init(&s[i], 0, 0); 
    for (i = 0; i < N; i++) {
        pthread_create(&tid[i], NULL, philosopher, &phil[i]); 
        printf("phil %d is thinking\n", phil[i] + 1);
    }
    for(i = 0; i < N; i++)
        pthread_join(tid[i], NULL);
    
}
