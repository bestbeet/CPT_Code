#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node NODE;
typedef struct{
    int count;
    NODE *top;
}STACK;
STACK* createStack(){
    STACK *head=(STACK*)malloc(sizeof(STACK));
    head->count = 0;
    head->top=NULL;
    return head;
}
int push(STACK* head,int data)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if(newnode!=NULL)
    {   newnode->data=data;
        newnode->link=head->top;
        head->top=newnode;
        head->count++;
        return 1;
    }
    else
        return 0;
}
int pop(STACK* head,int *dataOut)
{
    if(head->top==NULL)
        return 0;
    else
    {
        *dataOut=head->top->data;
        NODE *topnext=head->top->link;
        free(head->top);
        head->top=topnext;
        head->count--;
        return 1;
    }
}
int isOperand(char c)
{
    if(c>='0'&&c<='9')
        return 1;
    else
        return 0;
}
int isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return 1;
    else
        return 0;
}
int cal(int a,int b,char c)
{
    if(c=='+')
        return a+b;
    else if(c=='-')
        return a-b;
    else if(c=='*')
        return a*b;
    else if(c=='/')
        return a/b;
}
int evaluate(STACK *head,char *expr)
{
    while(expr!=NULL&&(*expr!='\0'))
    {
        if(isOperand(*expr))
        {   push(head,*expr-48);
            printf("push %c\n",*expr);
        }
        if(isOperator(*expr))
        {   int a,b;
            if(pop(head,&b)&&pop(head,&a))
            {   printf("apply %d %c %d = ",a,*expr,b);
                push(head,cal(a,b,*expr));
                printf("push %d\n",cal(a,b,*expr));
            }
            else
            {    printf("Invalid expression : missing operand\n");
                 exit(0);
            }
        }
        expr++;
    }
   if(head->count!=1)
   {    printf("Invalid expression: Too many operands\n");
        exit(0);
    }
    else{
        int result;
        pop(head,&result);
        return result;
    }
}
int main()
{
    printf("Enter a postfix expr: ");
    char expr[101];
    scanf("%[^\n]s",expr);
    int i;
    STACK *head=createStack();
    int result;
    result=evaluate(head,expr);
    if(result!=-1)
        printf("Result = %d",result);
    getch();
    return 0;
}
