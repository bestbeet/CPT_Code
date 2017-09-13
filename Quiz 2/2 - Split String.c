#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,c=0;
    char string[300],a;
    scanf("%s",string);
    scanf("\n%c",&a);
    c = strlen(string);
    for(i=0;i<c;i++)
    {
        if(string[i] == a)
        {
            string[i] = '\n';
        }
        printf("%c",string[i]);
    }

    return 0;
}
