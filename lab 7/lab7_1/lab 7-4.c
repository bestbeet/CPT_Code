#include <stdio.h>
#include <stdlib.h>

struct listnode // กำหนด struct listnode ไว้เก็บ linked lists
{
    int data; // กำหนด int data ไว้สำหรับในการเก็บข้อมูล
    struct listnode * nextptr; // กำนหด * nextptr ไว้สำหรับชี้ linked lists
};
typedef struct listnode LISTNODE; // ย่อ struct listnode ให้เหลือแต่  LISTNODE
typedef LISTNODE * LISTP;   // pointer to a list

//  return 1 if lst is empty, 0 otherwise
int isEmpty(LISTP lst);

//  create a new list with the node of value
LISTP createList(int value);

//  insert a value at the head of list
int cons(int value, LISTP * lst);

//  insert a value in the list(ordered list)
int insert(LISTP * lst, int value);

//  display element of the list
void printList(LISTP lst);

// delete the first node with value val
int deleteNode(LISTP *lst, int val);

int main()
{
    int a, b,c; // กำหนด int a กับ b
    LISTP listA = NULL; // กำหนด LISTP listA ให้เท่ากับ NULL

    printf("Enter integers to insert into the list\n");

    do // เข้า  loop do-while และจะหลุด loop เมื่อค่า b ไม่เท่ากับ 1
    {
        b = scanf("%d", &a); // รับค่า a มาแล้วให้ b เท่ากับค่า a ที่รับมา เพื่อดูว่าค่าที่รับมาเป็นตัวเลข หรือป่าว

        if (b == 1) // เช้าเงื่อนไข if ถ้า b == 1 ให้ทำใน if
        {
            if (insert(&listA, a)) // ถ้าเรียกใช้งาน insert เป็นจริง จะทำการพิมพ์ ค่า a แล้วบอกว่า was insered.
                printf("%d was inserted.\n", a);
            else // ถ้าไม่ใช้ if จะพิมพ์ว่า Cannot insert ค่า a
                printf("Cannot insert %d\n", a);
        }
    } while (b == 1);
    fflush(stdin); //   clear all input buffer
    printf("listA: ");
    printList(listA); // เรียกใช้งาน printList เพื่อทำการพิมม์ค่าที่เก็บเอาไว้ใน listA
    printf("\nEnter is value delete all nodes: ");
    scanf("%d", &a);
    c = deleteNode(&listA, a);
    if (c == 1)
		printf("%d Delete Success.\n", a);
    else
    	printf("Cannot Delete %d.\n", a);
    printf("listA delete all nodes with value val: ");
    printList(listA);

    exit(EXIT_SUCCESS);
}

//  return 1 if lst is empty, 0 otherwise
int isEmpty(LISTP lst)
{
    return (lst == NULL); // ถ้าเป็น node สุดท้ายทำการ ส่งค่ากลับไปว่าเป็นตัวสุดท้ายให้กับฟังก์ชันที่เรียกใช้
}

//  create a new list with the node of value
LISTP createList(int value)
{
    LISTP lst;
    lst = (LISTNODE * )malloc(sizeof(LISTNODE)); // จองหน่วยความจำให้ lst

    if (lst != NULL) // ถ้า lst ไม่เท่ากับ NULL
    {
        lst->data = value; // lst->data เท่ากับ value ที่ส่งมา
        lst->nextptr = NULL; // lst->nextptr เท่ากับ NULL
    }

    return lst; // ทำการ return lst ไปในฟังก์ชันที่ส่งค่า value มา
}

//  insert a value at the head of list
int cons(int value, LISTP * lst)
{
    LISTP pnewnode; // สร้าง LISTP pnewnode ขี้นมา
    pnewnode = (LISTNODE *)malloc(sizeof(LISTNODE)); // ทำการจองหน่วยความจำให้ pnewnode

    if (pnewnode == NULL) //
        return 0; // no memory available

    pnewnode->data = value; // ให้ pnewnode->data เก็บค่า value
    pnewnode->nextptr = * lst; // pnewnode->nextptr เก็บค่า *lst

    * lst = pnewnode; // แล้วให้ *lst เก็บค่า pnewnode

    return 1;
}

//  insert a value in the list(ordered list)
int insert(LISTP * lst, int value)
{
    LISTP newptr, prevptr, currentptr; // กำหนด LISTP 3 ตัว

    if (isEmpty(* lst)) // make a new list with the value
    {
        * lst = createList(value); // ให้ส่งค่า value ไปใน createList

        if (* lst != NULL)
            return 1;
        else
            return 0;
    }

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE)); // ทำการจองหน่วยความจำของ newptr

    if (newptr == NULL) // ถ้า newprt เป็น NULL จะจบการทำงาน
        return 0; // no memory available
    newptr->data = value; // newptr->data เก็บค่า value ที่ส่งมา
    newptr->nextptr = NULL; // ให้ newptr->nextptr เก็บค่า NULL

    if (value <= (* lst)->data) // insert value at the list head
    {
        return cons(value, lst); //  ทำการส่งค่า vale กับ lst ไปให้ cons
    }

    prevptr = NULL; // ให้ prevptr = NULL
    currentptr = * lst; // ให้ currentptr = * lst

    // search for the position to insert the value
    while (currentptr != NULL && (value > currentptr->data)) // ทำการเข้า loop while จะหลุด loop ก็ต่อเมื่อ  currentptr ไม่ใช่ node สุดท้าย และ ค่า value มากกว่า ค่า currentptr-> data
    {
        prevptr = currentptr;
        currentptr = currentptr->nextptr;
    }

    // insert the value inside the list or at the end
    prevptr->nextptr = newptr;
    newptr->nextptr = currentptr;

    return 1;
}

//  display element of the list
void printList(LISTP lst)
{
    if (isEmpty(lst)) // ถ้าค่าที่ได้ใน isEmpty เป็นจิง จะทำการพิมพ์ EOL
        printf("EOL\n"); // End of list
    else // ถ้าไม่ตรงเงื่อนไข if เข้า else
    {
        printf("(%d)==>", lst->data); // พิมพ์ค่าตัวเลขที่อยู่ใน lst->data
        printList(lst->nextptr); // ทำการเรียกใช้ printList ต่อเรื่อยๆ จนกว่าจะเจอ node สุดท้าย
    }
}

// add the last node with value
int add(LISTP *lst, int value)
{	LISTP newptr, curr;
    int i = 1;

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE));
    curr = (*lst);

    if (newptr)
    {
        newptr->data = value;
        newptr->nextptr = NULL;

        while (curr->nextptr != NULL)
        {
            curr = curr->nextptr;
        }
        curr->nextptr = newptr;

        return 1;
    }

    return 0;
}

// delete the first node with value val
int deleteNode(LISTP *lst, int val)
{	LISTP tempptr, currptr, prevptr; // กำหนด LISTP มา 3 ตัว

    if (!isEmpty(*lst)) // เข้า if ถ้าส่งไปเช็คที่ isEmpty เป็นจริง ให้ทำใน if
    {
        prevptr = *lst; // ให้ prevptr = *lst
        currptr = (*lst)->nextptr; // กำหนด currptr เก็บค่าของ (*lst)->nextptr

        if (val == prevptr->data) // ถ้า val == prevptr->data เพื่อทำการลบ node 1 ตัวที่เท่ากับ val
        {
            tempptr = prevptr; // tempptr เก็บ prevptr
            *lst = (*lst)->nextptr; // ให้ *lst เก็บ ค่าตัวถัดไปของ (*lst)->nextptr
            free(tempptr); // ทำการลบค่าที่อยู่ใน temptr
        }
        else // ถ้าไม่เข้า if ให้เข้า else
        {
            while ((currptr != NULL) && (val != currptr->data)) // จะวน loop-while จนกว่าจะถึง node สุดท้าย และทุก node ไม่มีค่าเท่ากับ val
            {
                prevptr = currptr; // ให้ prevptr = currptr;
                currptr = currptr->nextptr; // แล้วให้ currptr ชี้ไปที่ node ถัดไป currptr->nextptr;
            }

            if (currptr) // เงื่อนไข if ถ้า เป็นจริง
            {
                tempptr = currptr; // ให้ tempptr = currptr
                prevptr->nextptr = currptr->nextptr; // แล้วให้ prevptr->nextptr ชี้ไปที่ node ถัดไปของ currptr->nextptr
                free(tempptr); // ทำการคืนค่า tempptr
            }
        }
        return 1;
    }
    return 0;
}
