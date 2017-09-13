#include<stdio.h>
#include<string.h>
int main ()
{
    char *day[]={"Monday","Tuesday","Wednesday","Friday","Saturday","Sunday"};
    char *ad;
	int i,j,a;
	for(i=0;i<6;i++)
    {
		for(j=0;j<6;j++)
      	{
      		a=0;
      		a = strcmp(day[j],day[j+1]);
      		if(a==1)
      		{
      			ad = day[j];
      			day[j] = day[j+1];
      			day[j+1] = ad;
      		}
      	}
    }
    for(i=0;i<6;i++)
    {
    	printf("%s\n",day[i]);

    }
    return 0;
}
