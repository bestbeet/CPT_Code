#include<stdio.h>
typedef struct
{
    char name[30];
    int score;
}student;
void getStudent(student *s);
void totalScore(student b[]);
int main()
{
    int i;
    student st[5];
    student *as;
    as = st;
    for(i=0;i<5;i++)
		getStudent(&as[i]);
    totalScore(as);
    return 0;
}
void getStudent(student *s)
{
    printf("Enter name : ");
    scanf("%s",s->name);
    printf("Enter score : ");
    scanf("%d",&s->score);
}
void totalScore(student b[])
{
    int y=0,i;
    for(i=0;i<5;i++)
    {
        y += b[i].score;
    }
    printf("totalscore = %d",y);
}
