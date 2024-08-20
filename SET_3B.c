//d). Program to demonstrate IPC using shared memory
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

int main(void)
{
    int pid, shmid;
    char *p;

    shmid = shmget((key_t) 150, 20, IPC_CREAT| 0600);
    p = (char *)shmat(shmid, 0, 0);
    pid = fork();

    if (pid == 0)
        strcpy(p, "Demo of shared memory");
    else if (pid > 0)
        printf("%s\n", p);
    else
        perror("error!\n");
}
