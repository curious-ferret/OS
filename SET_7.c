//c). Program to simulate CPU scheduling algorithm for Round Robin scheduling.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, bt[15], wt[15], tat[15], rt[15], time = 0, Twt = 0, Ttat = 0, count = 0, ts;
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
                    time += ts;
                }
                else
                {
                    time += rt[i];
                    tat[i] = time;
                    Ttat += tat[i];

                    wt[i] = tat[i] - bt[i];
                    Twt += wt[i];

                    rt[i] = 0;
                    count++;
                }
            }
        }
    }

    avgWt = (float)Twt / n;
    avgTat = (float)Ttat / n;

    printf("\nP.No\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f\n", avgWt);
    printf("Average turn-around time: %.2f\n", avgTat);

    return 0;
}
