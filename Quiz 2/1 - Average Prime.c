#include<stdio.h>
int main()
{
    int check,x,y,n;
    float m=0,a;
    scanf("%d",&n);
    for(x=2;x<=n;x++)
    {
        check = 1;
        for(y=2;y<x;y++)
        {
            if(!(x%y))
            {
                check=0;
            }
        }
        if(check)
        {
            m = x;
            a++;
        }
    }
    printf("%.2f",m);
    return 0;
}
