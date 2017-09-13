#include <stdio.h>
#include <string.h>
#define N 6
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
    phonebook list[N] = {
                            {"Mario", "Maurer", "0895559555", 5, 7},
                            {"Billy", "Joe", "0897334488", 30, 10},
                            {"John", "Smith", "0842135320", 15, 12},
                            {"Joy", "Apple", "0922412011", 18, 7},
                            {"Saman", "Who", "0892130214", 18, 7},
                            {"Billy", "Teller", "0843621128", 20, 10}
                        };
 
    if((fp=fopen(fname, "wb")) == NULL){
        fprintf(stderr, "\nCAN\'N OPEN %s FOR WRITING\n", fname);
        return 1;
    }else printf("%s is created as binary file\n", fname);
    i = fwrite(list,N, sizeof(phonebook), fp);
    printf("%d persons are writen in %s\n", i, fname);
    fclose(fp);
    return 0;
}

