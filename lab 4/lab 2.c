#include<stdio.h>
#include<string.h>
#define SIZE 20
#define MAX 20
int is_goodname(char *s[]);
int main()
{
    char *name[SIZE],ch[SIZE][MAX];
    int a;
    name[0] = &ch[0][0];
    name[1] = &ch[1][0];
    printf("Enter Name: ");
    scanf("%s",&ch[0]);
    printf("Enter Surname : ");
    scanf("%s",&ch[1]);

    a = is_goodname(name);
    printf("%d",a);

    return 0;
}
int is_goodname(char *s[])
{
    int j,NA,SA;

    for(j=0;j<MAX;j++)
    {
        if((s[0][j] == 'a') || (s[0][j] == 'A'))
            NA++;
        if((s[1][j] == 'a') || (s[1][j] == 'A'))
            SA++;
    }
    if((NA>0)&&(SA>0))
        return 0;
    else
        return -1;

}
