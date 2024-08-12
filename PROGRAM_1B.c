//b). Program to reposition the file offset on Linux using lseek( ) system call.
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd;
    fd = open("seek.txt", O_RDWR);
    if (fd < 0)
    {
        perror("file seek.txt failed to open.\n");
        return 1;
    }

    char buf[50];
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    //SEEK CURSOR
    lseek(fd, 10, SEEK_CUR);
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    //SEEK SET
    lseek(fd, 10, SEEK_SET);
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    //SEEK END
    lseek(fd, 10, SEEK_END);
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    close(fd);
}
