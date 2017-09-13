#include<stdio.h>
#include<string.h>

char* find_char(char s[], char c);

int main()
{
    int a;
    char str[128];
    char c,*n;
    scanf("%s\n",&str);
    scanf("%c",&c);
    n = find_char(str,c);

    if(n != NULL)
        printf("%c",*n);
    else
        printf("Not found");

    return 0;
}
char* find_char(char s[], char c)
{
    int i,a;
    a = strlen(s);
    for(i=0;i<strlen(s);i++)
    {
        if( s[i] == c && s[i+1] != '\0')
        {
            return &s[i+1];
        }
    }
    return NULL;
}
