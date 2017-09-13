#include<stdio.h>
void area(int x , int y , float z[1]);
int main()
{
    int x,y;
    float z[1];
    scanf("%d %d",&x,&y);

    area(x,y,z);
    printf("%.2f",z[0]);

    return 0;
}
void area(int x , int y , float z[1])
{
    z[0] = (x*y)*0.5;

}
