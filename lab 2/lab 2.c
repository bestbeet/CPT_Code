#include<stdio.h>
#include<stdlib.h>
int ask_question(int x,int y);
int make_num(void);
void main()
{
    int x,y,result;

    x = make_num();
    y = make_num();
    while(1)
    {
        printf("%d * %d = ",x,y);
        result = ask_question(x,y);
        if(x*y != result)
        {
            printf("No, please try again.\n");
        }
        else
        {
            printf("Very good!\n");
            x = make_num();
            y = make_num();

        }
    }
}
int make_num(void)
{
    int n;
    n = rand();

    if((n<10) && (n>-10))
    {
        return n;
    }
    else
    {
        make_num();
    }
}
int ask_question(int x,int y)
{
    int n;
    scanf("%d",&n);
    return n;
}
