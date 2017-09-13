#include <stdio.h>
#include <string.h>
typedef struct{
   char name[12];
   char surname[20];
   char phone[12];
   int bday, bmonth;
}phonebook;

int main(){
    char fname[15] = "phonebook2.dat";
    int i = 0;
    FILE *fp;
    phonebook list;

    if((fp=fopen(fname, "rb")) == NULL){
        fprintf(stderr, "\nCAN\'N OPEN %s FOR WRITING\n", fname);
        exit(1);
    }
    printf("name             surname          phone         bday   bmonth\n");
    printf("-------------------------------------------------------------\n");
    while(!feof(fp)){
        fread(&list, sizeof(phonebook), 1, fp);
        if(list.name[0] == 'J') printf("%s\t\t %s\t\t %s\t %d\t  %d\n"
        , list.name, list.surname, list.phone, list.bday, list.bmonth);
    }
    fclose(fp);
    return 0;
}


