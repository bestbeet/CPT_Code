#include<stdio.h>

typedef struct{
        int TrueFalse;
        int sudokuTable[4][4];        
}sudoku;

sudoku input();
void show(sudoku t);
int check(sudoku t);
void search(sudoku t);

int main()
{
        int answer;
        printf("Sudoku 4#4\n");
        sudoku insudoku = input();
        printf("\n\nBefore Sudoku\n\n");
        show(insudoku);
        insudoku.TrueFalse = check(insudoku);
        
        if(insudoku.TrueFalse==1){
             printf("\nThis is SudokuTable\n");
             search(insudoku);
        }
        else 
             printf("\nThis is not SudokuTable\n");
        
        getch();
        return 0;
}
sudoku input()
{
       int i,j;
       sudoku t;
       /*for(i=0;i<4;i++){
            printf("Row %d: ",i+1);
            scanf("%d %d %d %d",&t.sudokuTable[i][0],&t.sudokuTable[i][1],&t.sudokuTable[i][2],&t.sudokuTable[i][3]);      
       }*/
       for(i=0;i<4;i++){
            printf("Row %d: ",i+1);
            for(j=0;j<4;j++){
                 scanf("%d",&t.sudokuTable[i][j]);
            }
       }
       return t;       
}
void show(sudoku t)
{
       int i,j;

       for(i=0;i<4;i++){
            printf("\t");
            for(j=0;j<4;j++){
                 printf("%d  ",t.sudokuTable[i][j]);      
            }
            printf("\n");
       }
}
int check(sudoku t)
{
       int i,j,k,l;
       int count[4]={0,0,0,0};
       
       
       for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                   if(t.sudokuTable[i][j]>0&&t.sudokuTable[i][j]<5){
                        for(k=0;k<4;k++){
                              if(t.sudokuTable[i][j]==count[k])
                                   return 0;
                              else
                                   if(k==3)
                                        count[j] = t.sudokuTable[i][j];
                        }
                   }
                   else if(t.sudokuTable[i][j]==0)
                        j=j;
                   else
                        return 0;
            }
            count[0]=0;count[1]=0;count[2]=0;count[3]=0;
       }
       for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                   if(t.sudokuTable[j][i]>0&&t.sudokuTable[j][i]<5){
                        for(k=0;k<4;k++){
                              if(t.sudokuTable[j][i]==count[k])
                                   return 0;
                              else
                                   if(k=3)
                                        count[j] = t.sudokuTable[j][i];
                        }
                   }
                   else if(t.sudokuTable[j][i]==0)
                        j=j;
                   else
                        return 0;
            }
       }
       return 1;
}
void search(sudoku t)
{
      int i,j,k,l,m;
      int ans[2];
      int count[4]={1,2,3,4};
      
      for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                  if(t.sudokuTable[i][j]==0){
                        l = i;
                        m = j;
                  }           
            }
      }
      for(i=0;i<4;i++){
            if(t.sudokuTable[l][i]!=0){
                  for(j=0;j<4;j++){
                        if(t.sudokuTable[l][i]==count[j])           
                              count[j]=0;
                  }          
            }
      }
      for(i=0;i<4;i++){
            if(count[i]!=0)
                  ans[0] = count[i];                  
      }
      count[0]=1; count[1]=2; count[2]=3; count[3]=4;
      
      for(i=0;i<4;i++){
            if(t.sudokuTable[i][m]!=0){
                  for(j=0;j<4;j++){
                        if(t.sudokuTable[i][m]==count[j])
                              count[j]=0;
                  }                     
            }                            
      }
      for(i=0;i<4;i++){
            if(count[i]!=0)
                  ans[1] = count[i];                  
      }
      if(ans[0]==ans[1]){
            printf("Answer of Sudoku is %d\n",ans[0]);
            printf("\n**This is New SudokuTable**\n\n");
            t.sudokuTable[l][m]=ans[0];
            show(t);
      }
      else
            printf("This Sudoku is not Answer!!\n");
}
