//c). Program to demonstrate IPC using message queues (two way communication)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>

int main(void)
{
    int pid, msg_id;
    char buffer[20], a[20];
    system("clear");

    msg_id = msgget((key_t) 179, IPC_CREAT| 0600);
    pid = fork();

    if (pid == 0)
    {
        strcpy(a, "1604-22-733-179");
        msgsnd(msg_id, a, 20, 0);
    }
    else if (pid > 0)
    {
        msgrcv(msg_id, buffer, 20, 0, 0);
        printf("message recieved: %s\n", buffer);
    }
    else
        perror("Unable to create child.\n");
}