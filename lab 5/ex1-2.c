#include <stdio.h>
int main(int argc, char *argv[]){
    FILE *f1;
    FILE *f2;
    int ch;
    if(argc != 3){
        printf("WRONG ARGUMENT!!");
        return 1;
    }

    f1_retry:

    f1 = fopen(argv[1], "r+");
    if(f1 != NULL){
        f2_retry:

        f2 = fopen(argv[2], "w+");
        if(f2 != NULL){

            while((ch = fgetc(f1)) != EOF){
                fputc(ch, f2);
            }

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

