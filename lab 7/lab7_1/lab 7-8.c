#include <stdio.h>
#include <stdlib.h>

struct listnode // ���ҧ listnode ����红�����
{
    int value; // ����红����ŵ���Ţ
    struct listnode * nextptr; // ����� node �Ѵ�
};

typedef struct listnode LISTNODE; // �ӡ������������� LISTNODE
typedef LISTNODE * LISTP; // ����������� *LISTP

int isEmpty(LISTP lst); // ��˹� pototye int isEmpty(LISTP lst); ���ҧ����� node �ش����
LISTP createlist(int value); // ��˹� pototye LISTP createlist(int value); ���ҧ�������Ѻ��Ѻ��� node
int addlist(LISTP * lst, int value); // ��˹� pototye int addlist �������Ѻ���� node
void printlist(LISTP lst); // ��˹� pototye void printlist(LISTP lst); �������Ѻ print ���� node �ء���

int main()
{
    LISTP lst = NULL; // ���ҧ lst ���ǡ�˹����g�� NULL
    int a, b; // ��˹� int a,b,i = 1
    int i = 1;

    do // ��� loop do-while
    {
        printf("Enter is number %d: ", i);
        b = scanf("%d", &a); // �ӡ���Ѻ���  a ��������� b = ��� a

        if (b) // ��Ҥ�� b �繨�ԧ����� if ��
        {
            if (addlist(&lst, a)) // ��� if ����觤�� �㹿ѧ���� addlist �����繨�ԧ����觾������������������
                printf("Add to list.\n");
            else // ��������� if ���͡������ͤ�������
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

    if (isEmpty(*lst)) // ��仵�Ǩ������� node �ش�����������
    {
        *lst = createlist(value); // ����纤�� value ���� *lst

        if (*lst != NULL)
            return 1;
        else
            return 0;
    }

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE)); // �ӡ�èͧ˹��¤����� newptr

    newptr->value = value; // �ӡ���纤�� value ���� newptr->value
    newptr->nextptr = *lst; // �纤�� node �Ѵ����� newptr->nextptr

    *lst = newptr; // ��� *lst �纤�� newptr

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

