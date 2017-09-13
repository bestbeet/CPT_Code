#include<stdio.h>
#include<stdlib.h>
int a[1000]={0},n;
void re(int p,int x,int t)
{   if(p>=t)
    {   int i;
       for( i=0;i<x;i++)
            printf("%d ",a[i]);
       printf("\n");
    }
    else
    {
        a[x]=1;
        re(p+1,x+1,t);
        if(p+2<=t)
        {
            a[x]=2;
            re(p+2,x+1,t);
        }
    }
}
int main()
{
    scanf("%d",&n);
    re(0,0,n);
    return 0;
}
