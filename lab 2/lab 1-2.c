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

    if(exponent>0)
    {
        return base*integerPower(base,exponent-1);
    }
    else
    {
        return 1;
    }
}
