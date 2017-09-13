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
    char name[12], surname[20], newph[12];
    FILE *fp;
    phonebook list;
    phonebook *old_list;
    if((fp=fopen(fname, "rwab+")) == NULL){
        fprintf(stderr, "\nCAN\'N OPEN %s FOR WRITING\n", fname);
        return 1;
    }
    tryA:
        printf("Enter name and surname : ");
        scanf("%s %s", name, surname);
        fflush(stdin);
        rewind(fp);
    while(!feof(fp)){
        fread(&list, sizeof(phonebook), 1, fp);
        if(strcmp(name, list.name) == 0 && strcmp(surname,list.surname) == 0){
            printf("%s %s %s\n", list.name, list.surname, list.phone);
            printf("Please Enter new phone number : ");
            scanf("%s", newph);
            strcpy(list.phone,newph);
            printf("%s %s %s\n", list.name, list.surname, list.phone);
            fwrite(&list,sizeof(phonebook), 1, fp);
            printf("The phone number is updated");
            fclose(fp);
            return 0;
        }else if(feof(fp)){
           printf("%s %s is not found!\n", name, surname);
           goto tryA;
        }
    }
    fclose(fp);
    return 0;
}
