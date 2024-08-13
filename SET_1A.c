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
        printf("Usage: ./a.out sourcefile destinationfile.\n");
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0)
    {
        perror("error in opening source file.\n");
        exit(1);
    }

    fd2 = open(argv[2], O_WRONLY| O_CREAT, 0644);

    while ((bytes = read(fd1, buffer, 1)) > 0)
        write(fd2, buffer, bytes);
    close(fd1);
    close(fd2);

    fd2 = open(argv[2], O_RDONLY);
    printf("Contents of the destination file: \n");
	while((bytes = read(fd2, buffer, 1)) > 0)
    {
		write(1, buffer, bytes);
	}
	close(fd2);
    printf("\n");
    return 0;
}
