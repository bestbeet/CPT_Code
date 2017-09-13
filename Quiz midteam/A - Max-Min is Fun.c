#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,min,max;
    scanf("%d",&a);
    min = a;
    max = a;
    while(1)
    {
        if(a == -1){
            break;
        }
        if(a < min){
            min = a;
        }
        if(a > max){
            max = a;
        }
        printf("Max = %d, Min = %d\n",max,min);
        scanf("%d",&a);
    }
    

    exit(EXIT_SUCCESS);
}