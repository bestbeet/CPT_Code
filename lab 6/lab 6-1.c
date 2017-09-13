#include<stdio.h>
#include<stdlib.h>
struct listnode { // ���ҧ struct ���� listnode
	int data; // ��˹������
	struct listnode *next; // ��˹�����������Ѻ��� Node
};
typedef struct listnode LN; // ��ͪ��� struct listnode

void insert_at_front(LN **hptr, int d); // ��˹� Pototype ����Ѻ����� Node
void print(LN *head); // ��˹� Pototype ����Ѻ������ҷ�������
int sum(LN *head); // ��˹� Pototype ����Ѻ�����ҷ���Ѻ��

int main(){
	LN *head = NULL; // ��˹� ��� head ��ҡѺ NULL
	int d; // �ӹ˴ d �繵���û����� int

	printf("Enter: ");
	do{
		scanf("%d", &d); // �Ѻ��� d �����
		if(d > 0){ // ������͹� if d > 0
			insert_at_front(&head, d); // �觷������ͧ head �Ѻ d �㹿ѧ��ѹ insert_at_front
		}
	}while(d > 0); // �����ش loop ��� d > 0
	printf("=");
	print(head); // �觤�ҷ�� head ���㹿ѧ��ѹ print
	printf("\n=%d", sum(head)); // �觤�ҷ�� head ���㹿ѧ��ѹ sum ���ǡ� return ����һ���

    return 0; // �觤����ѧ��� copmpiler
}

void insert_at_front(LN **hptr, int d){
	LN *newp; // ��˹����������
	newp = (LN*)malloc(sizeof(LN)); // �ӵ���������Ҩͧ˹��¤��������Ը� dynamic
	newp->data = d; // ��� newp->data = d
	newp->next = *hptr; // ��� newp->next = *hptr
	*hptr = newp; // ��� *hptr = newp
}

void print(LN *head){
	while( head != NULL ){ // ���ͤ�� head != NULL ��� loop ��
		printf("%d ", head->data); // ���Ƿӡ�þ�����ҷ��������͡��
		head = head->next; // ��� head = head->next
	}
}

int sum(LN *head){
	int sum=0; // ��˹� sum = 0 �繵���� int
	while( head != NULL ){ // ���ͤ�� head != NULL ��� loop ��
		sum+=head->data; // ��� sum += head->data
		head = head->next; // ��� head = head->next
	}
	return sum; // return sum �㹿ѧ��ѹ main
}
