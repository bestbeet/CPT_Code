#include<stdio.h>
int main()
{
	int x[] = {1,2,3}, y[] = {4,5,6},tmp,i;	
	int *m = x,*n = y;
	for (i=0;i<3;i++)
	{
		tmp = *m;
		*m= *n;
		*n = tmp;
		m++;
		n++;
	}
	printf("ANSWER X = %d %d %d \nANSWER Y = %d %d %d\n",
                   x[0],x[1],x[2],y[0],y[1],y[2]);
	
	return 0;
}
