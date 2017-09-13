#include<stdio.h>
int main()
{
    int x,y,z;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    if ((x<y && x>z) || (x>y && x<z))
        printf("%d",x);
    else if ((y<x && y>z) || (y>x && y<z))
        printf("%d",y);
    else if ((z<x && z>y) || (z>x && z<y))
        printf("%d",z);

    return 0;
}
