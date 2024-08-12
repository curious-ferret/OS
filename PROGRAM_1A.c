//a). Program to demonstrate the usage of file related system calls. (open, creat, close read, write).(Program to copy contents of one file to another using system calls. Also display the contents of the copied file on screen).
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    int fd1, fd2;
    char buffer[50];
    ssize_t bytes;

    if(argc != 3)
    {
        printf("Usage: ./a.exe sourcefile destinationfile.\n");
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0)
    {
        perror("error in opening source file.\n");
        exit(1);
    }

    fd2 = open(argv[2], O_WRONLY| O_CREAT, 0644);
    if(fd2 < 0)
    {
        perror("error in opening destination file.\n");
        close(fd1);
        exit(1);
    }

    while ((bytes = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        if (write(fd2, buffer, bytes) != bytes)
        {
            perror("error while writing to destination file.\n");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }
    
    close(fd1);
    close(fd2);
    return 0;
}
