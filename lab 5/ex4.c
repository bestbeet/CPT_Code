#include <stdio.h>
typedef struct{
    char name[21];
    char surname[21];
    char phone[11];
    int bday;
    int bmonth;
    int byear;
}phoneBook;

int main(){
    phoneBook list;
    FILE *file;

    file = fopen("phonebook.dat", "rab+");
    if(file == NULL){
        printf("ERROR!!");
        return 1;
    }

    while(!feof(file)){
        fflush(stdout);
        fread(&list, sizeof(phoneBook), 1, file);fflush(stdout);
        printf("%s %s %s %d %d %d\n", list.name, list.surname, list.phone, list.bday, list.bmonth, list.byear);
	}
    fclose(file);
    return 0;
}

