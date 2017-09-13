#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define NUM 10

void sort(char *n[],int x){
   int i,j,b;
   char *a;
   for(i=0;i<x;i++)
    {

       for(j=0;j<x-1;j++){
            b = strcmp(n[j],n[j+1]);
           if(b>0)
            {
               a = n[j];
               n[j] = n[j+1];
               n[j+1] = a;
           }
       }
   }
}

int main()
{
    char name[SIZE];
    int i,n;
    scanf("%d",&n);
    char *pst[n];
    for(i=0;i<n;i++){
        scanf("%s",name);
        pst[i]= malloc(strlen((name)+1)*sizeof(char));
        strcpy(pst[i],name);

    }
    sort(pst,n);
    for(i=0;i<n;i++){
        printf("%s\n",pst[i]);
    }

    getch();
    return 0;
}
