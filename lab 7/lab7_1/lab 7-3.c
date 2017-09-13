#include <stdio.h>
#include <stdlib.h>

struct listnode // ��˹� struct listnode ����� linked lists
{
    int data; // ��˹� int data �������Ѻ㹡���红�����
    struct listnode * nextptr; // �ӹ˴ * nextptr �������Ѻ��� linked lists
};
typedef struct listnode LISTNODE; // ��� struct listnode ����������  LISTNODE
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

// add the last node with value
int add(LISTP *lst, int value);

int main()
{
    int a, b; // ��˹� int a �Ѻ b
    int i,c;
    LISTP listA = NULL; // ��˹� LISTP listA �����ҡѺ NULL

    printf("Enter integers to insert into the list\n");

    do // ���  loop do-while ��Ш���ش loop ����ͤ�� b �����ҡѺ 1
    {
        b = scanf("%d", &a); // �Ѻ��� a ��������� b ��ҡѺ��� a ����Ѻ�� ���ʹ���Ҥ�ҷ���Ѻ���繵���Ţ ���ͻ���

        if (b == 1) // ������͹� if ��� b == 1 ����� if
        {
            if (insert(&listA, a)) // ������¡��ҹ insert �繨�ԧ �зӡ�þ���� ��� a ���Ǻ͡��� was insered.
                printf("%d was inserted.\n", a);
            else // �������� if �о������� Cannot insert ��� a
                printf("Cannot insert %d\n", a);
        }
    } while (b == 1);
    fflush(stdin); //   clear all input buffer
    printf("listA: ");
    printList(listA); // ���¡��ҹ printList ���ͷӡ�þ�����ҷ����������� listA
    printf("\nEnter the last node : ");
	scanf("%d",&c);
	i = add(&listA, c);
	if (i==1)
    {
        printf("Add success.\n");
        printf("listA add last node: ");
        printList(listA);
    }
    else
        printf("Add not success.\n");



    exit(EXIT_SUCCESS);
}

//  return 1 if lst is empty, 0 otherwise
int isEmpty(LISTP lst)
{
    return (lst == NULL); // ����� node �ش���·ӡ�� �觤�ҡ�Ѻ�����繵���ش�������Ѻ�ѧ��ѹ������¡��
}

//  create a new list with the node of value
LISTP createList(int value)
{
    LISTP lst;
    lst = (LISTNODE * )malloc(sizeof(LISTNODE)); // �ͧ˹��¤�������� lst

    if (lst != NULL) // ��� lst �����ҡѺ NULL
    {
        lst->data = value; // lst->data ��ҡѺ value �������
        lst->nextptr = NULL; // lst->nextptr ��ҡѺ NULL
    }

    return lst; // �ӡ�� return lst �㹿ѧ��ѹ����觤�� value ��
}

//  insert a value at the head of list
int cons(int value, LISTP * lst)
{
    LISTP pnewnode; // ���ҧ LISTP pnewnode �����
    pnewnode = (LISTNODE *)malloc(sizeof(LISTNODE)); // �ӡ�èͧ˹��¤�������� pnewnode

    if (pnewnode == NULL) //
        return 0; // no memory available

    pnewnode->data = value; // ��� pnewnode->data �纤�� value
    pnewnode->nextptr = * lst; // pnewnode->nextptr �纤�� *lst

    * lst = pnewnode; // ������� *lst �纤�� pnewnode

    return 1;
}

//  insert a value in the list(ordered list)
int insert(LISTP * lst, int value)
{
    LISTP newptr, prevptr, currentptr; // ��˹� LISTP 3 ���

    if (isEmpty(* lst)) // make a new list with the value
    {
        * lst = createList(value); // ����觤�� value �� createList

        if (* lst != NULL)
            return 1;
        else
            return 0;
    }

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE)); // �ӡ�èͧ˹��¤����Ӣͧ newptr

    if (newptr == NULL) // ��� newprt �� NULL �Ш���÷ӧҹ
        return 0; // no memory available
    newptr->data = value; // newptr->data �纤�� value �������
    newptr->nextptr = NULL; // ��� newptr->nextptr �纤�� NULL

    if (value <= (* lst)->data) // insert value at the list head
    {
        return cons(value, lst); //  �ӡ���觤�� vale �Ѻ lst ���� cons
    }

    prevptr = NULL; // ��� prevptr = NULL
    currentptr = * lst; // ��� currentptr = * lst

    // search for the position to insert the value
    while (currentptr != NULL && (value > currentptr->data)) // �ӡ����� loop while ����ش loop ���������  currentptr ����� node �ش���� ��� ��� value �ҡ���� ��� currentptr-> data
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
    if (isEmpty(lst)) // ��Ҥ�ҷ����� isEmpty �繨ԧ �зӡ�þ���� EOL
        printf("EOL\n"); // End of list
    else // ������ç���͹� if ��� else
    {
        printf("(%d)==>", lst->data); // ������ҵ���Ţ�������� lst->data
        printList(lst->nextptr); // �ӡ�����¡�� printList ���������� �����Ҩ��� node �ش����
    }
}

// add the last node with value
int add(LISTP *lst, int value)
{	LISTP newptr, curr;

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE)); // �ӡ�èͧ˹��¤����Ӣͧ��� newptr
    curr = (*lst); // ���  curr = *lst

    if (newptr) // ��� newptr �繨ԧ������͹�
    {
        newptr->data = value; // ����ҷ�� newptr->data �纤�ҷ������ ��ͤ�� value
        newptr->nextptr = NULL; // ����ҷ�� newptr->nextptr �纤�� NULL ��������������� node �ش����

        while (curr->nextptr != NULL) // ��� loop-while ���ͷӡ������� curr->nextptr �ӡ�ç����֧����ش����
        {
            curr = curr->nextptr;
        }
        curr->nextptr = newptr; // �������ش loop ��� curr->nextptr ����� NULL ���价�� node �����ͤ��  newptr

        return 1;
    }

    return 0;
}
