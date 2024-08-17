#include<stdio.h> 
#include<stdlib.h> 

int main(void)
{
    int i, j, n, rs[50], f[10], nf, k=0, avail, pf=0;
    float hr, mr;

    // Clear the screen
    system("clear");

    //n: number of pages
    printf("Enter number of pages: "); 
    scanf("%d", &n);

    //rs: reference string
    for (i = 1; i <= n; i++)
    {
        printf("Enter reference string %d: ", i); 
        scanf("%d", &rs[i]);
    }

    //nf: frame size
    printf("Enter frame size: "); 
    scanf("%d", &nf); 

    //initialising the frames to -1 meaning they are available
    //f: frames
    for (i = 0; i < nf; i++)
        f[i] = -1;

    printf("page frames:\n"); 
    for (i = 1; i <= n; i++)
    {
        avail = 0; 
        for (j = 0; j < nf; j++)
        {
            if (f[j] == rs[i])
                avail = 1;
        }
        if (avail == 0)
        {
            f[k] = rs[i]; 
            k = (k + 1) % nf; 
            pf++; 
            for (j = 0; j < nf; j++)
                    printf("%d\t", f[j]); 
            printf("PF no. %d", pf);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pf); 
    mr = (float) pf / n;
    hr = 1 - mr;
    //you can also use 
    //hr = (float)(n - pf) / n;
    printf("Hit Ratio: %.2f, Miss Ratio: %.2f\n", hr, mr);

    return 0;
}
