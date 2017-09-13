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
    file = fopen("phonebook.dat", "wab+");
    if(file == NULL){
        printf("ERROR!!");
        return 1;
    }
    for(i=0;i<count;i++){
        fflush(stdin);
        printf("#%d\n", i+1);
        printf("    NAME : "); gets(list[i].name);

        printf(" SURNAME : "); gets(list[i].surname);

        printf("   PHONE : "); gets(list[i].phone);

        printf("BIRTHDAY : \n");
        printf("         DAY :"); scanf("%d", &list[i].bday);
        printf("       MONTH :"); scanf("%d", &list[i].bmonth);
        printf("         YEAR:"); scanf("%d", &list[i].byear);
	}
    for(i=0;i<count;i++)
        fwrite(&list[i], 1, sizeof(phoneBook), file);
    printf("SAVE COMPLETE!!\n");
    fclose(file);
    return 0;
}


