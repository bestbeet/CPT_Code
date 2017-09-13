#include<stdio.h>
#include<string.h>
struct song{
  char title[128];
  double duration;
};
typedef struct song Song;
struct listnode{
  Song s;
  struct listnode *next;
};
typedef struct listnode LN;
void insert(LN **hptr, Song *sp);
Song *input_song();
double sum_duration(LN *head);
int main()
{
  Song *sp;
  LN *head=NULL;
  int i;
  for(i=0;i<5;i++)
  {
     sp = input_song();
     insert(&head,sp);
  }
  for(i=0;i<5;i++)
     printf("S%.2d: ",i+1);
  LN *p=head;
  while(p!=NULL)
  {
     printf("%s ",p->s.title);
     p=p->next;
  }
  printf("= %.2lf",sum_duration(head));
  return 0;
}
void insert(LN **hptr, Song *sp)
{
    LN *newnode,*cur=*hptr;
    LN *prev=*hptr;
    newnode=(LN*)malloc(sizeof(LN));
    newnode->s=*sp;
    newnode->next=NULL;
    if(*hptr==NULL)
        *hptr=newnode;
    else
    {
        if(strcmp(sp->title,cur->s.title)<0)
        {    newnode->next=*hptr;
             *hptr=newnode;
        }
        else
        {   while((strcmp(cur->s.title,sp->title)<0)&&(cur->next!=NULL))
            {   prev=cur;
                cur=cur->next;
            }
            if((strcmp(prev->s.title,sp->title)<0)&&
            (strcmp(cur->s.title,sp->title)>0))
            {   prev->next=newnode;
                newnode->next=cur;
            }
            else
                cur->next=newnode;
        }
    }
}
Song *input_song()
{
    Song *s;
    s=(Song*)malloc(sizeof(Song));
    scanf("%s %lf",&s->title,&s->duration);
    return s;
}
double sum_duration(LN *head)
{
    double sum=0.0;
    while(head!=NULL)
    {   sum=sum+(head->s.duration);
        head=head->next;
    }
    return sum;
}
