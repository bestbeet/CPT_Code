#include<stdio.h>
int main()
{
    char a;
    printf("Enter : ");
    scanf("%c",&a);

    switch(a)
    {
        case 'r' : case 'R' : printf("RED");
        break;
        case 'g' : case 'G' : printf("GREEN");
        break;
        case 'y' : case 'Y' : printf("YELLOW");
        break;
        case 'b' : case 'B' : printf("BLUE");
        break;
        default : printf("Other Colors");
    }

    return 0;
}
