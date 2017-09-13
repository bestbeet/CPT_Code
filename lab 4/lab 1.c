#include<stdio.h>
typedef struct
{
    int day;
    int month;
    int year;
}Data;
void get_date(Data *a);
int main()
{
    Data num,*b;
    b = &num;
    get_date(b);
    printf("%d/%d/%d\n",b->day,b->month,b->year);
    return 0;
}
void get_date(Data *a)
{
    printf("Enter day/month/year :");
    scanf("%d/%d/%d",&a->day,&a->month,&a->year);
}
