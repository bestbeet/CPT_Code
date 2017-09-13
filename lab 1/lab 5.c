#include<stdio.h>
int main()
{
    int money,a,b,c;
    printf("Enter money : ");
    scanf("%d",&money);
    if(money<=20000&&money>= 100)
    {
        a = money/1000;
        b = (money%1000)/500;
        c = ((money%1000)%500)/100;
        printf("\n1000 = %d\n 500 = %d\n 100 = %d",a,b,c);
    }
    else
    {
        printf("\nfould");
    }

    return 0;
}
