#include<stdio.h>
struct listnode{
    int data;
    struct listnode *next;
};
typedef struct listnode LN;
void insert_front(LN **head,int value);
void insert_back(LN **head,int value);
void printList(LN *head);
int main()
{
    int a,b;
    int i = 1;
    LN *head=NULL;
    printf("Enter integers to insert into the list\n");
 	printf("(enter a non-numeric character to terminate of input)\n ");
 	do
 	{ 	b=scanf("%d",&a);
 		if (b==1)
	 	{
 			    if(a%2==0)
 			        insert_front(&head,a);
 			    else
 			        insert_back(&head,a);
 				printf("%d was inserted.\n",a);
 		}
 	} while (b == 1 && ++i <= 10);
 	fflush(stdin);
 	printList(head);
 	getch();
 	return 0;
}
void insert_front(LN **head,int value)
{
    LN *newnode; // ���ҧ *newnode
    newnode=(LN*)malloc(sizeof(LN)); // �ӡ�èͧ˹��¤�����
    newnode->data=value; // ��� nenode->data ��ҡѺ value
    newnode->next=*head; // ��� newnode->next ��ҡѺ *head
    *head=newnode; // ��� *head ��ҡѺ newnode
} // �ѧ���ѹ����������Ѻ�����Ţ��������Ţ���������������� node
void insert_back(LN **head,int value)
{
    LN *newnode; // ���ҧ *newnode
    LN *tail=*head; // ��� *tail ��ҡѺ��� *head
    newnode=(LN*)malloc(sizeof(LN)); // �ӡ�èͧ˹��¤�����
    newnode->data=value; // ��� nenode->data ��ҡѺ value
    newnode->next=NULL; // ��� nenode->data ��ҡѺ NULL
    if(*head==NULL) // ��� if ��Ҥ�� head == NULL
        *head=newnode; // ��� *head �纤�� node ����
    else
    {   while(tail->next!=NULL) // ��� loop-while ���͹䢤�ͤ�� tail->next �繤�ҷ����ҡѺ NULL ����ش�ѹ��
            tail=tail->next; // ��� tail �纤�� tail ��ǶѴ�
        tail->next=newnode; // ��� tail ��ǶѴ��� newnode
    }
} // �ѧ���ѹ����������Ѻ�����Ţ��������Ţ��������������� node

void printList(LN *head)
{
    while(head!=NULL)
    {   printf("%d==>",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
