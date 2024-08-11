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
        perror("fork system call unsuccessfull.\n");
        exit(1);
    }
    else if(pid == 0)//Child Process
    {
        printf("This is child process.\n");
        printf("Child id: %d.\n", getpid());
        printf("Parent id: %d.\n", getppid());
        printf("Pid: %d.\n", pid);
        system("ps-l");
        printf("\n");
    }

    else//Parent Process
    {
        sleep(2);
        printf("This is parent process.\n");
        printf("Parent id: %d.\n", getpid());
        printf("Parent's parent id: %d.\n", getppid());
        printf("Pid: %d.\n", pid);
        system("ps-l");
        printf("\n");
    }
    return 0;
}