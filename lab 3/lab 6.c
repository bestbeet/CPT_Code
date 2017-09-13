#include<stdio.h>
#include<math.h>
double hypotenuse(double *x);
int main()
{
    double y[2];
    double *a = y;
    printf("Enter x : ");
    scanf("%lf",&y[0]);
    printf("Enter y : ");
    scanf("%lf",&y[1]);

    printf("%.2f",hypotenuse(a));
    return 0;

}
double hypotenuse(double *x)
{
    double k;
    k = sqrt((*x*(*x))+(*(x+1)*(*(x+1))));
    return k;
}
