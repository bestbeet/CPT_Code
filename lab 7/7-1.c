#include<stdio.h>
#include<stdlib.h>

struct song{ // กำหนด struct song
  char title[128]; // กำหนดไว้เก็บชื่อเพลง
  double duration; // กำหนดความยาวเพลง
};
typedef struct song Song;
struct listnode{
  Song s;
  struct listnode *next;
};
typedef struct listnode LN;
void insert(LN **hptr, Song *sp);
LN *find_tail(LN *head);
double sum_duration(LN *head);
int main(){

  int i = 0;
  Song buf[5];
  LN *head = NULL;
  for ( i=0 ; i<5 ; i++){
    scanf("%s",buf[i].title);
    scanf("%lf",&buf[i].duration);
    insert(&head,&buf[i]);
  }
  for(i=0; i<5; i++){
  	printf("S%02d: ", i+1);
  }

  printf("= %.2f",sum_duration(head));

  return 0;

}
void insert(LN **hptr, Song *sp){
    LN *newp, *temp = *hptr;
	newp = (LN*)malloc(sizeof(LN));
	newp->s = *sp;
	newp->next = NULL;

	if( *hptr == NULL ){
		*hptr = newp;
	}
	else{
		temp = *hptr;
		temp = find_tail(temp);
		temp->next = newp;
    }

}
LN *find_tail(LN *head){
    LN *temp;
    temp = head;
    while( temp->next != NULL ){
        temp = temp->next;
    }

    return temp;
}
double sum_duration(LN *head){
    double sum = 0;
    while( head != NULL ){
		sum += head->s.duration;
		head = head->next;
	}

	return sum;
}
