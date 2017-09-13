#include <stdio.h>
int main(){
    FILE *f1;
    FILE *f2;
    char f_name[20];
    char ch;

    f1_retry:
    printf("Please Enter Origin File name : ");
    scanf("%s", f_name);

    f1 = fopen(f_name, "r+");
    if(f1 != NULL){
        f2_retry:
        printf("Please Enter Copy File name : ");
        scanf("%s", f_name);
        f2 = fopen(f_name, "w+");
        if(f2 != NULL){
            /**TODO**/
            while((ch = fgetc(f1)) != EOF){
                fputc(ch, f2);
            }
            /**END TODO**/
        }else{
            printf("ERROR NEW OR UPDATE FILE\n");
            goto f2_retry;
        }
    }else{
         printf("FILE DOESN\'T EXIST!!\n");
         goto f1_retry;
    }
    return 0;
}


