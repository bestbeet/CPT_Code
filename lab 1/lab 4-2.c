#include<stdio.h>
int main()
{
    int a,x[3],i;

    printf("Enter number : ");
    scanf("%d",&a);

    for(i=0;i<3;i++)
    {
        x[i] = a*(i+1);
    }
    a = x[0]+x[1]+x[2];

    printf("%d",a);

    return 0;
}
