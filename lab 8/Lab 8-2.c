#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXLEN 101 //maximum char in an expression
// Definition of stack data structures
// Stack node
typedef struct node
{ int data;
struct node* link; // pointer to next node
} STACK_NODE;
// Stack head
typedef struct
{ int count;
STACK_NODE* top; //pointer to stack top node
} STACK;
typedef STACK* STACKP; //pointer to stack
// Create a new stack
STACKP createStack();
// Check if character c is a digit
int isOperand(char c)
{ if (c>='0' && c<='9') return 1;
else return 0;
}
// Check if character c is an operator
int isOperator(char c)
{ if (c=='+' || c=='-' || c=='*' || c=='/') return 1;
else return 0;
}
// Push stack
int pushStack(STACKP stk, int n);
// Pop stack
int popStack(STACKP stk, int* n);
// Empty stack checking
int isEmpty(STACKP stk)
{ if (stk->count == 0) return 1;
else return 0;
}
// Evaluate a postfix expression using stack
int eval(STACKP stk, char expr[]);
int main()
{
    STACKP stk1;
    int i, ok, n;
    char expr[MAXLEN]="";
    printf("Enter a postfix expression: ");
    scanf("%[^\n]s", expr); // read a string until Enter key pressed
    printf("Evaluate the expression %s\n", expr);
    stk1 = createStack();
    ok=eval(stk1,expr);
    return 0;
}

STACKP createStack()
{
	STACKP stk;
	int cout=0;
	stk=malloc(sizeof(STACK));
	stk->top=NULL;
	stk->count=0;
	return stk;
}

int pushStack(STACKP stk, int n)
{
	STACK_NODE* newNodePtr;
	newNodePtr=malloc(sizeof(STACK_NODE));
	newNodePtr->data=n;
	newNodePtr->link=NULL;
	if(stk!=NULL)
	{
		if(stk->count==0){
			stk->top=newNodePtr;
			stk->count=stk->count+1;
			return 1;
		}
		else
		{
			newNodePtr->link=stk->top;
			stk->top=newNodePtr;
			stk->count=stk->count+1;
		}
	}

//	printf("push %d\n",newNodePtr->data);
	return 0;
	}
// Pop stack: n gets the value from the stack top, stack top node is
// removed and stack top pointer is also updated
// return 1 if successful, 0 if empty stack
int popStack(STACKP stk, int* n)
{
    STACK_NODE* tmp;
    if(isEmpty(stk))
        return 0;
	tmp=stk->top;
	*n=tmp->data;
	stk->top=stk->top->link;
	free(tmp);
	stk->count = stk->count-1;
 	return 1;
}
// Evaluate a postfix expression: use stack during calculation
// the result of expression stays on the stack top
// return 1 if valid expression, 0 if invalid expression
int eval(STACKP stk, char expr[])
{
    int i, ok, n, a, b,one,two;
    int countOp=0, countOperand=0;
    i=0; ok=0;
	for(i=0;i<strlen(expr);i++){

        if(isOperand(expr[i])==1)
        {
            if(isOperand(expr[i+1]) == 1)
            {
                countOperand++;
                one = (expr[i])-'0';
                two = (expr[i+1])-'0';
                ok = ((one*10)+two);
                printf("push %d\n",ok);
                pushStack(stk,ok);
                i=i+2;
            }
            else
            {
                printf("Push %c\n",expr[i]);
                countOperand++;
                ok=expr[i]-'0';
                pushStack(stk,ok);
            }


        }
        else
        {

            if(isOperator(expr[i])==1)
            {
                popStack(stk,&a);
                popStack(stk,&b);
                if(expr[i]=='+')
                {
                    printf("apply %d + %d  =  push %d\n",b,a,b+a);
                    pushStack(stk,b+a);
                }
                if(expr[i]=='-')
                {
                    printf("apply %d - %d  =  push %d\n",b,a,b-a);
                    pushStack(stk,b-a);
                }
                if(expr[i]=='*')
                {
                    printf("apply %d * %d  =  push %d\n",b,a,b*a);
                    pushStack(stk,b*a);
                }
                if(expr[i]=='/')
                {
                    printf("apply %d / %d  =  push %d\n",b,a,b/a);
                            pushStack(stk,b/a);
                }
                countOp++;
            }

            }
	}

	if(countOperand > countOp+1)
    {
                    printf("Invalid expression: Too many operands\n");
                    return 0;
    }
    else if(countOperand < countOp+1)
    {
         printf("Invalid expression: - missing operand\n");
         return 0;
    }
    else if(countOperand == countOp+1)
    {
         printf("Result = %d\n",stk->top->data);
         return 1;
    }

	}
