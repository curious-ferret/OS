//SSTF Disk Scheduling Algorithm
#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h> 

int main(void)
{
    //hdpos: head position
    //tseek: seek time
    //min: minimum seek distance
    //dist: distance between cpos and req
    //index: stores index of request closest to cpos (i.e., the one with the minimum dist)
    int req[20], n, hdpos, tseek = 0, i, temp[20], min, dist, index, cpos, cnt = 0; 
    float avgmv;
    system("clear");

    printf("Enter the number of requests: "); 
    scanf("%d", &n);

    printf("Enter the disk read requests\n"); 
    for (i = 0; i < n; i++)
    {
        printf("Request %d: ", i + 1); 
        scanf("%d", &req[i]);
        temp[i] = req[i];
    }
    printf("Enter head position: "); 
    scanf("%d", &hdpos);

    printf("SSTF sequence is:\n"); 
    //cpos: current position
    cpos = hdpos;

    while (cnt < n)
    {
        min = INT_MAX; 
        for (i = 0; i < n; i++)
        {
            if (temp[i] != -1)
            {
                dist = abs(req[i] - cpos); 
                if (min > dist)
                {
                    min = dist; 
                    index = i; 
                }
            }
        }
        tseek += min;
        temp[index] = -1; 
        cnt++; 
        cpos = req[index];
        printf("%d -> ", req[index]); 
        if (cnt == n)
            break;
    }
    avgmv = (float) tseek / n; 
    printf("\nTotal Seek Time = %d\n", tseek); 
    printf("Average Movement = %.2f\n", avgmv);
}
