#include<stdio.h>
int main ()
{
    int num[5][2]={1,6,2,7,3,8,4,9,5,10};
    int *nptr;
    int i=0,j=0;
    nptr = num;

    for(i=0;i<5;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("num[%d][%d] = %d\t",i,j,*nptr++);
        }
        printf("\n");
    }
    printf("\n\n");

    *nptr=&num[5][2];

    for(i=4;i>=0;i--)
    {
        for(j=1;j>=0;j--)
        {
            printf("num[%d][%d] = %d\t",i,j,*--nptr);
        }
        printf("\n");
    }

    return 0;
}

