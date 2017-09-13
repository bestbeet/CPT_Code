#include<stdio.h>
int main()
{
    int i,a,b,c;
    scanf("%d",&a);
    for(i=0;i<10;i++)
    {
        scanf("%d",&b);
        printf("T%02d: ",i+1);
        c = b-a;
        if(((-3<= c) && (c <= 3)) && (c != 0))
        {
            printf("=Very close\n");
        }
        else if((b<a))
        {
            printf("=Too small\n");
        }
        else if((b>a))
        {
            printf("=Too large\n");
        }
        else if (b == a)
        {
            printf("=Victory\n");
            break;
        }
        if (i == 9)
            printf("=Game over\n");
    }
}
