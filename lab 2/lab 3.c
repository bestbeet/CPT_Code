#include<stdio.h>
int F_x(int x);
int main()
{
    int x;
    printf("Enter x : ");
    scanf("%d",&x);
    printf("F(x) = %d",F_x(x));

    return 0;
}
int F_x(int x)
{
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    else
        return F_x(x-1)+F_x(x-2);
}
