#include<stdio.h>
int integerPower(int base,int exponent);
int main()
{
    int x,y;

    printf("Enter base , exponent : ");
    scanf("%d %d",&x,&y);
    printf("%d",integerPower(x,y));

    return 0;
}
int integerPower(int base,int exponent)
{
    int sum=1,i;

    if(exponent>0)
    {
        for(i=1;i<=exponent;i++)
        {
            sum = base*sum;
        }
        return sum;
    }
    else
    {
        return 1;
    }
}
