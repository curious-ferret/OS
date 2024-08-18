//Least Recently Used Page Replacement Algorithm

#include<stdio.h> 
#include<stdlib.h> 

int main(void)
{
    int i, j, n, rs[50], f[10], nf, k, min, count[10], flag[20], pf = 0, next = 1; 
    float hr, mr;
    system("clear");

    printf("Enter number of pages: "); 
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Reference string %d: ", i + 1); 
        scanf("%d", &rs[i]); 
        //flag is used to check if the page is already in a frame
        flag[i] = 0;
    }

    printf("Enter frame size: "); 
    scanf("%d", &nf);

    for (i = 0; i < nf; i++)
    {
        //count is used to store the least recently used page
        count[i] = 0; 
        f[i] = -1;
    }

    printf("\npage frame\n"); 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < nf; j++)
        {
            if (f[j] == rs[i])
            {
                flag[i] = 1; 
                count[j] = next; 
                next++;
            }
        }
        if (flag[i] == 0)
        {
            if (i < nf)
            {
                f[i] = rs[i]; 
                count[i] = next; 
                next++;
            }
            else
            {
                min = 0; 
                for (j = 1; j < nf; j++)
                {
                    if (count[min] > count[j]) 
                        min=j;
                }
                f[min] = rs[i]; 
                count[min] = next; 
                next++;
            }
            pf++;
        }
        for (j = 0; j < nf; j++)
            printf("%d\t", f[j]); 
        if (flag[i] == 0)
            printf("pf no is %d", pf); 
        printf("\n");
    }

    printf("Total Page Frames are %d\n", pf); 
    mr = (float) pf / n;
    hr = 1 - mr;
    printf("Hit Ratio: %.2f\nMiss Ratio: %.2f\n", hr, mr);
}
