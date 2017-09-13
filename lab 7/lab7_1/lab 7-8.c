#include <stdio.h>
#include <stdlib.h>

struct listnode // สร้าง listnode ไว้เก็บข้อมูล
{
    int value; // ไว้เก็บข้อมูลตัวเลข
    struct listnode * nextptr; // ไว้ชี้ node ถัดไป
};

typedef struct listnode LISTNODE; // ทำการย่อให้เหลือ LISTNODE
typedef LISTNODE * LISTP; // ย่อให้เหลือ *LISTP

int isEmpty(LISTP lst); // กำหนด pototye int isEmpty(LISTP lst); สร้างไว้เช็ค node สุดท้าย
LISTP createlist(int value); // กำหนด pototye LISTP createlist(int value); สร้างไว้สำหรับสลับค่า node
int addlist(LISTP * lst, int value); // กำหนด pototye int addlist ไว้สำหรับเพิ่ม node
void printlist(LISTP lst); // กำหนด pototye void printlist(LISTP lst); ไว้สำหรับ print ค่าใน node ทุกตัว

int main()
{
    LISTP lst = NULL; // สร้าง lst แล้วกำหนดให้gป็น NULL
    int a, b; // กำหนด int a,b,i = 1
    int i = 1;

    do // เข้า loop do-while
    {
        printf("Enter is number %d: ", i);
        b = scanf("%d", &a); // ทำการรับค่า  a แล้วให้ค่า b = ค่า a

        if (b) // ถ้าค่า b เป็นจริงก็เช้า if ได้
        {
            if (addlist(&lst, a)) // เช้า if ถ้าส่งค่า ไปในฟังก์ชั้น addlist แล้วเป็นจริงจะสั่งพิมพ์ว่าเพิ่มค่าแล้ว
                printf("Add to list.\n");
            else // ถ้าไม่เข้า if จะยอกว่าเพื่อค่าไม่ได้
                printf("Cannot add to list.\n");
        }
    } while (b == 1 && ++i <= 10);

    printlist(lst);

    return 0;
}

int isEmpty(LISTP lst)
{
    return (lst == NULL);
}

LISTP createlist(int value)
{
    LISTP newptr;

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE));

    if (newptr)
    {
        newptr->value = value;
        newptr->nextptr = NULL;
    }

    return newptr;
}

int addlist(LISTP * lst, int value)
{
    LISTP newptr;

    if (isEmpty(*lst)) // ส่งไปตรวจดูว่าเป็น node สุดท้ายหรือไม่
    {
        *lst = createlist(value); // ส่งไปเก็บค่า value ไว้ใน *lst

        if (*lst != NULL)
            return 1;
        else
            return 0;
    }

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE)); // ทำการจองหน่วยความจำ newptr

    newptr->value = value; // ทำการเก็บค่า value ไว้ใน newptr->value
    newptr->nextptr = *lst; // เก็บค่า node ถัดไปไว้ใน newptr->nextptr

    *lst = newptr; // ให้ *lst เก็บค่า newptr

    if (newptr->nextptr != NULL)
        return 1;

    return 0;
}

void printlist(LISTP lst)
{
    if (isEmpty(lst))
        printf("EOL.");
    else
    {
        printf("%d-->", lst->value);
        printlist(lst->nextptr);
    }
}

