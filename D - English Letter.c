#include<stdio.h>
int main()
{
    int a;
    char b;
    while(1)
    {
        scanf(" %c",&b);
        a = b;
        if( 65 <= a && a <= 90)
        {
            a = a-65;
            printf("Char:=%d\n",++a);

        }
        else if( 97 <= a && a <= 122)
        {
            a = a-97;
            printf("Char:=%d\n",++a);

        }
        else if ( a > 26 )
        {
            printf("Char:End.");
            break;
        }
    }
    return 0;
}
