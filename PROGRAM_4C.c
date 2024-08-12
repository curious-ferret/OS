#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void)
{
    int i, n, bt[15], wt[15], tat[15], rt[15], temp = 0, Twt = 0, Ttat = 0, count = 0, ts;
    float avgWt, avgTat;
    system("clear");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time slice: ");
    scanf("%d", &ts);

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while(count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                if (rt[i] > ts)
                {
                    rt[i] -= ts;
                    temp += ts;
                }
                else
                {
                    temp += rt[i];
                    tat[i] = temp;
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    Twt += wt[i];
                    count++;
                }
            }
        }
    }

    Ttat = temp;

    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        Ttat += tat[i];
    }
    avgWt = (float)Twt / n;
    avgTat = (float)Ttat / n;

    printf("\n P.no\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    printf("\nAverage waiting time: %.2f\n", avgWt);
    printf("Average turn-around time: %.2f\n", avgTat);
}