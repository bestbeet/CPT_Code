#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main()
{

   char  s[SIZE];
   int x,i;
   int j,b;
   scanf("%d",&x);
   char *n[x],*as;

   for(i=0;i<x;i++)
   {
       scanf("%s",s);
       n[i] = s;

   }

    for(i=0;i<x;i++)
    {
        for(j=0;j<x-1;j++)
        {
            b = 0;
            b = strcmp(n[j],n[j+1]);
            if(b < 0)
            {
                as = n[j];
                n[j] = n[j+1];
                n[j+1] = as;
            }
        }
    }



   for(i=0;i<x;i++)
   {
       printf("%s\n",n[i]);
   }

    exit(EXIT_SUCCESS);
}
