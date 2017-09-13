#include<stdio.h>
#include<math.h>
double hypotenuse(double x, double y);
int main()
{
    double x,y;
    printf("Enter x : ");
    scanf("%lf",&x);
    printf("Enter y : ");
    scanf("%lf",&y);

    printf("%.2f",hypotenuse(x,y));
    return 0;

}
double hypotenuse(double x, double y)
{
    double k;
    k = sqrt((x*x)+(y*y));
    return k;
}
