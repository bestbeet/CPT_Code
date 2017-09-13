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
    phoneBook *list;
    FILE *file;
    int i = 0, count;
    printf("PLEASE ENTER COUNT OF INFORMATION : ");
    scanf("%d", &count);
    list = (phoneBook *) malloc (sizeof(phoneBook)*count);
    file = fopen("phonebook.txt", "wa+");
    if(file == NULL){
        printf("ERROR!!");
        return 1;
    }
    fprintf(file, "NAME            SURNAME           PHONE          BIRTHDAY\n");
    fprintf(file, "---------------------------------------------------------\n");
    for(i=0;i<count;i++){
        fflush(stdin);
        printf("#%d\n", i+1);
        printf("    NAME : "); gets(list[i].name);
        fprintf(file, "%-15s\t", list[i].name);
        printf(" SURNAME : "); gets(list[i].surname);
        fprintf(file, "%-15s\t", list[i].surname);
        printf("   PHONE : "); gets(list[i].phone);
        fprintf(file, "%-15s\t",list[i].phone);
        printf("BIRTHDAY : \n");
        printf("         DAY :"); scanf("%d", &list[i].bday);
        printf("       MONTH :"); scanf("%d", &list[i].bmonth);
        printf("         YEAR:"); scanf("%d", &list[i].byear);
        fprintf(file, "%d-%d-%d\n", list[i].bday, list[i].bmonth, list[i].byear);
    }
    printf("SAVE COMPLETE!!\n");
    fclose(file);
    return 0;
}

