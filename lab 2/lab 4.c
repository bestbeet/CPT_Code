#include<stdio.h>
#include<string.h>
int testPalindrome(char a[],int x,int y);
int main()
{
    char a[30];
    int x,y = 0;
    printf("Enter string : ");
    gets(a);
    x = strlen(a)-1;
    y = testPalindrome(a,x,y);
    if(y == 0)
        printf("y = %d",y);
    else
        printf("y = %d",y);

    return 0;
}
int testPalindrome(char a[],int x,int y)
{
    if(x==y)
        return 1;
    else if(a[x] == a[y])
        return 1*testPalindrome(a,x-1,y+1);
    else if (a[x] != a[y])
        return 0;
}
