//FCFS Disk Scheduling Algorithm

#include<stdio.h> 
#include<stdlib.h>

int main(void) 
{
    int req[20], n, hdpos, tseek = 0, i; 
    float avgmv;
    system("clear");

    //n: number of requests
    printf("Enter the number of requests: "); 
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the disk read request %d: ", i + 1); 
        scanf("%d", &req[i]);
    }

    //hdpos: head position
    printf("Enter head position: "); 
    scanf("%d", &hdpos);

    printf("FCFS sequence:\n"); 
    for(i = 0; i < n; i++) 
    {
        printf("%d -> ", req[i]);
        //tseek: total seek time
        tseek += abs(req[i] - hdpos); 
        hdpos = req[i];
    }

    //calculating the average movement
    avgmv = (float) tseek / n; 
    printf("\nTotal Seek Time = %d\n", tseek); 
    printf("Average Movement = %.2f\n", avgmv);
}