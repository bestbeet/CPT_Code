#include<stdio.h>
#define SIZE 5
int get_values(double *val);
double mean (int n, double *nums);
int main()
{
    int count;
    double vals[SIZE];
    count = get_values(vals);

    printf("\nMEAN : %.2lf",mean(count,vals));

    return 0;
}
int get_values(double *val)
{
    int n;
    printf("Enter values: ");
    for (n=0; n < SIZE && scanf("%lf", val+n) == 1; n++);
    return n;
}
double mean(int n, double *nums){
    double total = 0;
    int i;
    for(i=0;i<n;i++)
    total += *(nums+i);
    return total/n;
}
