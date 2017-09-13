#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct profile {
  int vote;
  char grade;
  int score;
};
struct star{
   char name[SIZE];
   struct profile p;
};
typedef struct star Actor;
int main()
{
    int num,i,j;
    scanf("%d",&num);
    Actor a[num];
    Actor b;
    for(i= 0;i<num;i++)
    {
        scanf("%s %d %c",a[i].name,&a[i].p.vote,&a[i].p.grade);
    }
    for(i= 0;i<num;i++)
    {
        if(a[i].p.grade == 'A')
            a[i].p.score = a[i].p.vote*4;
        else if(a[i].p.grade == 'B')
            a[i].p.score = a[i].p.vote*3;
        else if(a[i].p.grade == 'C')
            a[i].p.score = a[i].p.vote*2;
        else if(a[i].p.grade == 'D')
            a[i].p.score = a[i].p.vote*1;
        else if(a[i].p.grade == 'E')
            a[i].p.score = a[i].p.vote*0;
    }
    for(i= 0;i<num;i++)
    {
        for(j= 0;j<num-1;j++)
        {
            if(a[j].p.score < a[j+1].p.score)
            {
                b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
            }
        }
    }
    for(j= 0;j<num;j++)
        printf("%s %d %c %d\n",a[j].name,a[j].p.vote,a[j].p.grade,a[j].p.score);
    exit(EXIT_SUCCESS);
}
