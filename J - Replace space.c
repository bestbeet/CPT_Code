#include <stdio.h>
#include <stdlib.h>
void replace_space(char *s, char c);
int main()
{
    char str[50],*p,c;
    gets(str);
    scanf("%c",&c);
    p = str;
    replace_space(p,c);

    printf("%s",str);
    exit(EXIT_SUCCESS);
}
void replace_space(char *s, char c)
{
    int i;
    for(i=0;*(s+i)!='\0';i++)
    {
        if(*(s+i)==' ')
            *(s+i)=c;
    }
}
