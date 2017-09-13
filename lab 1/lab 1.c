#include<stdio.h>
int main()
{
    int i,j,x[3],tmp;

    printf("Enter three number : ");

    for(i=0;i<3;i++)
    {
        scanf("%d",&x[i]);
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(x[j]<x[j+1])
            {
                tmp = x[j];
                x[j] = x[j+1];
                x[j+1] = tmp;
            }
        }
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("%d\t",x[i]);
    }

    return 0;
}
