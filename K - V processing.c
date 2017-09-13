#include <stdio.h>
#include<stdlib.h>
struct set
{
    float factor;
    int amount;
    int *values;
};
typedef struct set SET;

struct v
{
    int k;
    SET set;
};
typedef struct v V;

void input_v(V *p);
int sum(int d[], int len);
float f_v(V *p);

int main()
{
    V v;
    int i;

    input_v(&v);
    v.set.amount = sum(v.set.values,v.set.amount);
    printf("%.1f", f_v(&v));
    return 0;
}
void input_v(V *p)
{
    int i;
    scanf("%d",&p->k);
    scanf("%f",&p->set.factor);
    scanf("%d",&p->set.amount);
    p->set.values = (int *)malloc(p->set.amount*sizeof(int));
    for(i=0;i<p->set.amount;i++)
    {
        scanf("%d",p->set.values+i);
    }

}
int sum(int d[], int len)
{
    int i,sum=0;
    for(i=0;i<len;i++)
    {
        sum += *(d+i);
    }
    return sum;
}

float f_v(V *p)
{
    float f;
    f = p->k+(p->set.factor*p->set.amount);
    return f;
}
