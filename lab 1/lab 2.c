#include<stdio.h>
int main()
{
    int i=0,a,x[3],sum = 0;

    printf("Enter number : ");
    scanf("%d",&a);

    while(i<3)
    {
        x[i] = a*(i+1);
        i++;
    }

    sum = x[0]+x[1]+x[2];
    printf("%d",sum);

    return 0;
}
