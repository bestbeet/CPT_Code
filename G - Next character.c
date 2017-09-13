#include <stdio.h>
#include <stdlib.h>
void to_next(char* cptr);
int main()
{
  char c;
  char *cptr;
  scanf("%c",&c);
  cptr = &c;
  to_next(cptr);

  printf("%c",*cptr);

  return 0;
}
void to_next(char* cptr)
{
   if(*cptr =='z')
      *cptr = *cptr-25;
   else
       *cptr = *cptr+1;
}
