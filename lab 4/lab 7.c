#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char name[30];
	int score;
}student;
int num=0;
void getStudent(student *s);
void totalScore(student b[]);
int main()
{
	int i;
	printf("Enter volue student :");
	scanf("%d",&num);
	student *st;
	st = (student *)malloc(num*sizeof(student));
	for(i=0;i<num;i++)
		getStudent(&st[i]);
        totalScore(st);
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
	int x=0,i;
	for(i=0;i<num;i++)
		x+=b[i].score;
    printf("Total score is %d",x);
}


