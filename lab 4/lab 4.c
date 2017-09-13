#include<stdio.h>
int main ()
{
    char *day[]={"Monday","Tuesday","Wednesday","Friday","Saturday","Sunday"};
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<10;j++)
        {
            if((day[i][j] == 's')||(day[i][j] == 'S'))
            {
                printf("%s\n",day[i]);
            }
        }
    }
    return 0;
}
