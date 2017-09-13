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
    LN *newnode; // สร้าง *newnode
    newnode=(LN*)malloc(sizeof(LN)); // ทำการจองหน่วยความจำ
    newnode->data=value; // ให้ nenode->data เท่ากับ value
    newnode->next=*head; // ให้ newnode->next เท่ากับ *head
    *head=newnode; // ให้ *head เท่ากับ newnode
} // ฟังกฺ์ชันนี้ไว้สำหรับเพิ่มเลขคู่ถ้าเป็นเลขคู่นั้นให้ไปอยู่ท้าย node
void insert_back(LN **head,int value)
{
    LN *newnode; // สร้าง *newnode
    LN *tail=*head; // ให้ *tail เท่ากับค่า *head
    newnode=(LN*)malloc(sizeof(LN)); // ทำการจองหน่วยความจำ
    newnode->data=value; // ให้ nenode->data เท่ากับ value
    newnode->next=NULL; // ให้ nenode->data เท่ากับ NULL
    if(*head==NULL) // เข้า if ถ้าค่า head == NULL
        *head=newnode; // ให้ *head เก็บค่า node ใหม่
    else
    {   while(tail->next!=NULL) // เข้า loop-while เงื่อนไขคือค่า tail->next เป็นค่าที่เท่ากับ NULL จะหลุดทันที
            tail=tail->next; // ให้ tail เก็บค่า tail ตัวถัดไป
        tail->next=newnode; // ให้ tail ตัวถัดไปเป็น newnode
    }
} // ฟังกฺ์ชันนี้ไว้สำหรับเพิ่มเลขคู่ถ้าเป็นเลขคี่นั้นให้ไปอยูหัว node

void printList(LN *head)
{
    while(head!=NULL)
    {   printf("%d==>",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
