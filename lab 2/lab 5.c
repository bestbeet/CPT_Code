#include<stdio.h>
void forIJ(int i,int j);
void recursiveIJ(int i,int j);
int main()
{
    forIJ(0,0);
    recursiveIJ(0,0);
    return 0;
}
void forIJ(int i,int j)
{
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d",j);
        }
    }
    printf("\n");
}
void recursiveIJ(int i,int j)
{
    if(i != 5)
    {
        if(j != 5)
        {
            printf("%d",j);
            recursiveIJ(i,j+1);
        }
        else
        {
            recursiveIJ(i+1,0);
        }
    }
}
