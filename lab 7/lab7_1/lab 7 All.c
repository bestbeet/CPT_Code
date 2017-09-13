#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    int data;
    struct listnode * nextptr;
};
typedef struct listnode LISTNODE;
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

//  return the number of elements in the list
int length1(LISTP lst);
int length2(LISTP lst);

// add the last node with value
int add(LISTP *lst, int value);

// delete the first node with value val
int deleteNode(LISTP *lst, int val);

// delete all nodes with value val
int deleteAll(LISTP *lst, int val);

//  sum of all element in the list
int sumList(LISTP lst);

int main()
{
    int a, b, c;
    LISTP listA = NULL;

    printf("Enter integers to insert into the list\n");
    printf("(Enter a non-numeric character to terminate of input)\n");
	printf("-n to Add linked list\n");

    do
    {
        b = scanf("%d", &a);

        if (b == 1)
        {
            if (insert(&listA, a))
                printf("%d was inserted.\n", a);
            else
                printf("Cannot insert %d\n", a);
        }
    } while (b == 1);
    fflush(stdin); //   clear all input buffer
    printf("listA: ");
    printList(listA);
	printf("\nEnter the last node : ");
	scanf("%d",&c);
	add(&listA, c);
    printf("listA add last node: ");
    printList(listA);
    printf("length list(for)    : %d\n", length1(listA));
    printf("length list(recurse): %d\n", length2(listA));
    printf("\n");
   	printf("Enter is value delete first nodes: ");
    scanf("%d", &a);
    c = deleteNode(&listA, a);
    if (c == 1)
		printf("%d Delete Success.\n", a);
    else
    	printf("Cannot Delete %d.\n", a);

    printf("listA delete first nodes with value val: ");
    printList(listA);
    printf("\nEnter is value delete all nodes: ");
    scanf("%d", &a);
    c = deleteAll(&listA, a);
    printf("listA delete all nodes with value val: ");
    printList(listA);
    printf("sumlistA = %d\n",sumList(listA));
    //  printf("Length of listA = %d\n", length(listA));


    exit(EXIT_SUCCESS);
}


//  return 1 if lst is empty, 0 otherwise
int isEmpty(LISTP lst)
{
    return (lst == NULL);
}

//  create a new list with the node of value
LISTP createList(int value)
{
    LISTP lst;
    lst = (LISTNODE * )malloc(sizeof(LISTNODE));

    if (lst != NULL)
    {
        lst->data = value;
        lst->nextptr = NULL;
    }

    return lst;
}

//  insert a value at the head of list
int cons(int value, LISTP * lst)
{
    LISTP pnewnode;
    pnewnode = (LISTNODE *)malloc(sizeof(LISTNODE));

    if (pnewnode == NULL)
        return 0; // no memory available

    pnewnode->data = value;
    pnewnode->nextptr = * lst;

    * lst = pnewnode;

    return 1;
}

//  insert a value in the list(ordered list)
int insert(LISTP * lst, int value)
{
    LISTP newptr, prevptr, currentptr;

    if (isEmpty(* lst)) // make a new list with the value
    {
        * lst = createList(value);

        if (* lst != NULL)
            return 1;
        else
            return 0;
    }

    newptr = (LISTNODE *)malloc(sizeof(LISTNODE));

    if (newptr == NULL)
        return 0; // no memory available
    newptr->data = value;
    newptr->nextptr = NULL;

    if (value <= (* lst)->data) // insert value at the list head
    {
        return cons(value, lst);
    }

    prevptr = NULL;
    currentptr = * lst;

    // search for the position to insert the value
    while (currentptr != NULL && (value > currentptr->data))
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
    if (isEmpty(lst))
        printf("EOL\n"); // End of list
    else
    {
        printf("(%d)==>", lst->data);
        printList(lst->nextptr);
    }
}

//  return the number of elements in the list -> for-loop
int length1(LISTP lst)
{
    int n;

    for (n = 1; lst->nextptr != NULL; n++)
        lst = lst->nextptr;

    return n;
}

//  return the number of elements in the list -> recurse function
int length2(LISTP lst)
{
    if (lst->nextptr == NULL)
        return 1;
    else
        return (1 + length2(lst->nextptr));

    return 0;
}
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
{	LISTP tempptr, currptr, prevptr;

    if (!isEmpty(*lst))
    {
        prevptr = *lst;
        currptr = (*lst)->nextptr;

        if (val == prevptr->data)
        {
            tempptr = prevptr;
            *lst = (*lst)->nextptr;
            free(tempptr);
        }
        else
        {
            while ((currptr != NULL) && (val != currptr->data))
            {
                prevptr = currptr;
                currptr = currptr->nextptr;
            }

            if (currptr)
            {
                tempptr = currptr;
                prevptr->nextptr = currptr->nextptr;
                free(tempptr);
            }
        }

        return 1;
    }

    return 0;
}
// delete all nodes with value val
int deleteAll(LISTP *lst, int value)
{
    LISTP currptr, prevptr, tempptr;
    int i = 0;

    while ((*lst)->data == value)
    {
        tempptr = *lst;
        *lst = (*lst)->nextptr;
        free(tempptr);
        i++;

        if(isEmpty(*lst))
            return 0;
    }

    prevptr = *lst;
    currptr = (*lst)->nextptr;

    while (currptr != NULL)
    {
        if ((currptr->nextptr == NULL)
                        && (value == currptr->data))
        {
            tempptr = currptr;
            prevptr->nextptr = NULL;
            currptr = NULL;
            i++;
            continue;
        }
        else if (value == currptr->data)
        {
            tempptr = currptr;
            currptr = currptr->nextptr;
            prevptr->nextptr = currptr;
            free(tempptr);
            i++;
        }
        else
        {
            prevptr = currptr;
            currptr = currptr->nextptr;
        }
    }

    return i;
}
//  sum of all element in the list
int sumList(LISTP lst)
{
    LISTP curr;
    int sum = 0;

    curr = lst;

    while (curr->nextptr != NULL)
    {
        sum += curr->data;
        curr = curr->nextptr;
    }

    return sum;
}
