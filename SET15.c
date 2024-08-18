//Banker's Algorithm
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 

int main(void)
{
    //Variable definitions:
    //max: max resources required   
    //alloc: already allocated resources  
    //need: resources needed
    //avail: resources available
    //fin: processes that have finished execution
    //safe: safe sequence of processes
    int max[10][10], alloc[10][10], need[10][10], avail[10], fin[10], safe[10]; 
    //pr_cnt: process count
    //res_count: resources count
    //process: used to select process that can be safely executed
    //count: counts the number of processes that are safely executed
    int pr_cnt, res_cnt, i, j, process, count = 0;

    system("clear");

    printf("ENTER THE SYSTEM STATE INFORMATION\n"); 
    
    //Input: number of processes
    printf("Enter the number of processes: "); 
    scanf("%d", &pr_cnt);

    //initialising all processes's finished status to zero(false)
    for (i = 0; i < pr_cnt; i++)
        fin[i] = 0;
    
    //Input the number of resource type
    //Note: a resource type can have multiple instances
    printf("Enter the number of resource types: "); 
    scanf("%d", &res_cnt);

    // Input: Maximum resources for each process
    printf("\nEnter the max matrix for all processes: \n"); 
    for (i = 0; i < pr_cnt; i++)
    {
        for(j = 0; j < res_cnt; j++)
        {
            printf("Enter max info of process[%d][%d]: ", i + 1, j + 1); 
            scanf("%d", &max[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Input: Allocated resources for each process
    for (i = 0; i < pr_cnt; i++)
    {
        for (j = 0; j < res_cnt; j++)
        {
            printf("Enter allocated info of process[%d][%d]: ", i + 1, j + 1); 
            scanf("%d", &alloc[i][j]);
        }
        printf("\n");
    }

    //input: available resources
    printf("\nEnter the available resources:\n"); 
    for (i = 0; i < res_cnt; i++)
    {
        //you can also use available[%d] while prompting for input
        printf("Resource[%d]= ", i + 1); 
        scanf("%d", &avail[i]);
    }

    //calculating the need matrix
    for (i = 0; i < pr_cnt; i++)
    {
        for (j = 0; j < res_cnt; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    //Banker's Algorithm
    do
    {
        //printing available resources
        printf("\nAvailable resources are:\n"); 
        for (j = 0; j < res_cnt; j++)
            printf("%d\t", avail[j]);

        //printing out the max, allocated and need matrices
        printf("\n\n\tMAX MATRIX:\t\tALLOCATION MATRIX:\t\tNEED MATRIX\n"); 
        for (i = 0; i < pr_cnt; i++)
        {
            for (j = 0; j < res_cnt; j++)
                printf("%d\t", max[i][j]);
        printf("\t"); 
            for (j = 0; j < res_cnt; j++)
                printf("%d\t", alloc[i][j]);
        printf("\t"); 
            for (j = 0; j < res_cnt; j++)
                printf("%d\t", need[i][j]);
        printf("\n");
        }

        process = -1; 

        //finding a process that can be executed
        for (i = 0; i < pr_cnt; i++)
        {
            if (fin[i] == 0)
            {
                process = i; 
                for (j = 0; j < res_cnt; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        process = -1; 
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }

        // If a process is found
        if (process != -1)
        {
            safe[count] = process + 1; 
            count++; 

            // Allocate resources and mark process as finished
            for (j = 0; j < res_cnt; j++)
            {
                avail[j] += alloc[process][j]; 
                need [process][j] = 0;
                alloc[process][j] = 0; 
                max[process][j] = 0; 
                fin[process] = 1;
            }
        }
    } while (count != pr_cnt && process != -1); 
    
    // checking if system is in safe state
    if(count == pr_cnt)
    {
        printf("the system is in a safe state\n"); 
        printf("Safe sequence:< "); 
        for (i = 0; i < pr_cnt; i++)
            printf("%d ", safe[i]); 
        printf(">\n");
    }
    else
        printf("the system is in unsafe state!!\n");
}