#include<stdio.h>
int main()
{
	char x[50];
	int i,sum = 0;
	char *a = x;
	gets(x);
	for (i=0;i<50;i++)
	{
		if(*(a+i) == '\0')
			break;
		else
			sum++;
	}
	printf("%d\n",sum);
	
	return 0;
}
