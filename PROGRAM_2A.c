//Usage of process related system calls (fork(), getpid(), getppid())
//fork failure = -1
//fork upon success child = 0
//fork upon success parent = any +ve number

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pid;
    printf("Demonstration of fork system call.\n\n");

    pid = fork();
    if(pid < 0)//failure of fork() scenario
    {
        perror("fork system call has failed.\n");
        exit(0);
    }
    else if(pid == 0)//Child Process
    {
        printf("This is child process.\n");
        printf("Child id is %d.\n", getpid());
        printf("Parent id is %d.\n\n", getppid());
    }

    else//Parent Process
    {
        //you can include the below sleep function if you want to view the child process first
        //sleep(1);
        printf("This is parent process.\n");
        printf("Parent id is %d.\n", getpid());
        printf("Parent's parent id is %d.\n\n", getppid());
    }
    return 0;
}