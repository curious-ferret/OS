//Using un-named pipes to implement two-process communication through Echo server application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    int pid, a[2], b[2];
    char str[30], buff1[30], buff2[30];
    system("clear");

    pipe(a);
    pipe(b);
    pid = fork();
    if(pid == 0)
    {
        //to specify the size in read and write function, you can use either
        //strlen(x) + 1  or  sizeof(x)
        //where x is a char array
        strcpy(str, "child says hi");
        write(a[1], str, strlen(str) + 1);
        sleep(2);
        read(b[0], buff1, sizeof(buff1));
        printf("(through pipe b)\nResponse from parent is '%s'\n", buff1);
    }
    else
    {
        read(a[0], buff2, sizeof(buff2));
        printf("(through pipe a)\nRequest from child process is '%s'.\n", buff2);
        strcpy(buff2, "parent says hello");
        write(b[1], buff2, strlen(buff2) + 1);
    }
}
