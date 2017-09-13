#include<stdio.h>
int main()
{
	int x[6],i;
	int *a = x;
	for(i = 0 ;i < 5; i++)
	{
	    a++;
        printf("Please Enter %d value : ", i+1);
        scanf("%d", a);
    }
    for( i = 0; i < 5; i++)
    {
        printf("address : %d : value : %d\n", a, *a);
        a--;
    }
	return 0;
}
