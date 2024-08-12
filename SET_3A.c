//c). Program to get the attributes of a file on Linux using stat system call.
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char * argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd;
    struct stat buf;

    fd = stat(argv[1], &buf);
    if (fd < 0)
    {
        perror("Statistics of the given file could not be retrived.\n");
        exit(1);
    }

    printf("Inode:\t\t\t%ld\n", buf.st_ino);
    printf("User id:\t\t%d\n", buf.st_uid);
    printf("Group id:\t\t%d\n", buf.st_gid);
    printf("no.of links:\t\t%ld\n", buf.st_nlink);
    printf("Size:\t\t\t%ld\n", buf.st_size);
    printf("Permissions:\t\t%d\n", buf.st_mode);
    printf("Last status change:\t%s", ctime(&buf.st_ctime));
    printf("Last file access:\t%s", ctime(&buf.st_atime));
    printf("Last file modification:\t%s", ctime(&buf.st_mtime));
}
