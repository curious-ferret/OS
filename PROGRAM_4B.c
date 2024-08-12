//b). Program to simulate CPU scheduling algorithm for Shortest Job First scheduling.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n, bt[15], wt[15], tat[15], p[15], temp, Twt = 0, Ttat = 0;
    float avgWt, avgTat;
    system("clear");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[i])
            {
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;

                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) //calculation of waiting time
    {
        wt[i] = wt[i-1] + bt[i-1];
        Twt += wt[i];
    }

    for (i = 0; i < n; i++) //calculation of turn-around time
    {
        tat[i] = wt[i] + bt[i];
        Ttat += tat[i];
    }

    avgWt = Twt * 1.0 / n;
    avgTat = Ttat * 1.0 / n;

    //printing out the final answer in the form of matrix
    printf("\n P.no\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f\n", avgWt);
    printf("Average turn-around time: %.2f\n", avgTat);
}