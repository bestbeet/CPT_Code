#include<stdio.h>
#include<math.h>
double hypotenuse(double x, double y);
double (*pointerhypotenuse)(double x,double y);
int main()
{
    double x,y;
    printf("Enter x : ");
    scanf("%lf",&x);
    printf("Enter y : ");
    scanf("%lf",&y);
    pointerhypotenuse = hypotenuse;
    printf("%.2lf",(*pointerhypotenuse)(x,y);
}
double hypotenuse(double x, double y)
{
    double k;
    k = sqrt((x*x)+(y*y));
    return k;
}
