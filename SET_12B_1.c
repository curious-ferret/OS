//named pipes
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char str1[100], str2[100];
    system("clear");

    fd = mkfifo("fifo-179", 0644);
    printf("Named pipe has been created.\n");

    while (1)
    {
        //opening the pipe and sending message through keyboard
        fd = open("fifo-179", O_WRONLY);
        fgets(str1, 100, stdin);
        write(fd, str1, strlen (str1) + 1);
        close(fd);
        printf("User1: %d has sent the a message .\n", getpid());

        //opening the pipe and reading the message
        fd = open("fifo-179", O_RDONLY);
        read(fd, str2, sizeof(str2));
        printf("User2: %s\n", str2);
        close(fd);
    }
}
