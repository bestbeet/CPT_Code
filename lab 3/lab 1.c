#include<stdio.h>
int main()
{
    float n = 1.0,*m = &n;
    printf("&n = %d\n",&n);
    printf("n = %.2f\n",n);
    printf("&m = %d\n",&m);
    printf("m = %d\n",m);
    printf("*m = %.2f",*m);
    return 0;
}
