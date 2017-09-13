#include<stdio.h>
#include<stdlib.h>
struct listnode {
	int data; // กำหนดตัวแปร
	struct listnode *next; // สร้าง struct ชื่อ listnode
};
typedef struct listnode LN; // ย่อชื่อ struct listnode

void insert_at_back(LN **hptr, int d); // กำหนด Pototype สำหรับเชื่อม Node
void print(LN *head); // กำหนด Pototype สำหรับพิมพ์ค่าที่เก็บไว้
int sum(LN *head); // กำหนด Pototype สำหรับรวมค่าที่รับมา

int main(){
	LN *head = NULL; // กำหนด ให้ head เท่ากับ NULL
	int d; // กำนหด d เป็นตัวแปรประเภท int

	printf("Enter: ");
	do{
		scanf("%d", &d); // รับค่า d เข้ามา
        if(d > 0){ // เข้าเงื่อนไข if d > 0
			insert_at_back(&head, d); // ส่งที่อยู่ของ head กับ d ไปในฟังก์ชัน insert_at_front
		}
	}while(d > 0); // การหลุด loop คือ d > 0
	printf("= ");
	print(head); // ส่งค่าที่ head เก็บไปในฟังก์ชัน print
	printf("\n=%d", sum(head)); // ส่งค่าที่ head เก็บไปในฟังก์ชัน sum แล้วก็ return ค่ามาปริ๊น

    return 0; // ส่งค่าไปยังตัว copmpiler
}
void insert_at_back(LN **hptr, int d){
	LN *newp, *temp = *hptr; // กำหนดตัวแปรใหม่ แล้วกำหนดให้อีก 1 ตัว มีค่าเท่ากับ *hptr
	newp = (LN*)malloc(sizeof(LN)); // นำตัวแปรใหม่มาจองหน่วยความจำโดยวิธี dynamic
	newp->data = d; // ให้ newp->data = d
	newp->next = NULL; // ให้ newp->next = NULL

	if( *hptr == NULL ){ // if *hptr == NULL
		*hptr = newp; // ให้ *hptr = newp
	}
	else{ // เมื่อไม่เข้า if
		temp = *hptr; // temp = *hptr;
		while( temp->next > NULL ){ // เงื่อนไขเข้า while คือ temp->next > NULL
			temp = temp->next; // ให้ temp = temp->next
		}
		temp->next = newp; // ให้ temp->next = newp
    }
}

void print(LN *head){
	while( head != NULL ){ // เมือค่า head != NULL เข้า loop ได้
		printf("%d ", head->data); // แล้วทำการพิมพ์ค่าที่เก็บไว้ออกมา
		head = head->next; // ให้ head = head->next
	}
}

int sum(LN *head){
	int sum=0; // กำหนด sum = 0 เป็นตัวแปร int
	while( head != NULL ){ // เมือค่า head != NULL เข้า loop ได้
		sum+=head->data; // ให้ sum += head->data
		head = head->next; // ให้ head = head->next
	}
	return sum; // return sum ไปในฟังก์ชัน main
}
