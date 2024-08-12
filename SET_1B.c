//Un-named pipes
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    int pid, a[2];
    char str[30], buff[30];
    system("clear");

    pipe(a);
    pid = fork();
    if(pid == 0)
    {
        strcpy(str, "Demo Output");
        write(a[1], str, strlen(str) + 1);
        printf("Child process has written on pipe a.\n");
    }
    else
    {
        read(a[0], buff, sizeof(buff));
        printf("Parent process has recieved %s through the read pipe.\n", buff);
    }
}
