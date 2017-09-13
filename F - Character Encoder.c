#include<string.h>
#include<stdio.h>
char enc_char(char c);
int chack_char(char c);
int main()
{
    char c;
    int i,n;
    while(1)
    {
        scanf("%c",&c);
        if(feof(stdin))
        {
            break;
        }
        c = enc_char(c);
        printf("%c",c);
    }

       return 0;
 }
 char enc_char(char c)
 {
     int a;
     if(chack_char(c)==1)
     {
         if(c + 2 <= 'z')
            return  c+2;
         else {
            return 'a' + c - 'z' +1;
         }
     }
     else if(chack_char(c)==0)
     {
         if(c-1>='A')
            return c-1;
         else
         {
             return 'Z';
         }
     }
     else return c;

 }
 int chack_char(char c)
 {
      if(c >= 'a' && c<='z')
         return 1;
      else if(c >= 'A' && c<='Z')
         return 0;
      else return -1;
 }
