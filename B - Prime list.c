#include<stdio.h>
int main()
{
    int check,x,y,n;
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
            printf("%d, ",x);
        }
    }
    return 0;
}
