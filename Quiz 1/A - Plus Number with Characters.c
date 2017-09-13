#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,sum[100]={0},check;
    char numa[100],numb[100],*s1,*s2;
    scanf("%s",numa);
    scanf("%s",numb);
    s1=&numa[strlen(numa)-1];
    s2=&numb[strlen(numb)-1];
    for(i=0;i<strlen(numa);i++)
    {sum[i] += ((*s1-48)+(*s2-48));
        if(sum[i]>9){
            sum[i]-=10;
            sum[i+1]+=1;
        }
        s1--;
        s2--;
    }
    if(((numa[0]-48)+(numb[0]-48)>9))
        check=strlen(numa);
    else
        check = strlen(numa)-1;

    for(i=check;i>=0;i--)
        printf("%d",sum[i]);

    exit(EXIT_SUCCESS);
}
