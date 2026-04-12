#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define Row 5
#define Column 5

void free_mx(int ***mx, size_t row){

if(mx && *mx){
  for(int i = 0; i < row; i++){

    free((*mx)[i]);
    (*mx)[i] = NULL;
  }

free(*mx);
*mx = NULL;
}

}


bool print_mx(int **mx,int r,int c){

if(mx && r > 0 && c >0){
size_t row = r;
size_t col = c;
  for(int i = 0; i < row; i++){

    if(mx[i]){

        for(int j = 0 ; j < col;j++){

          printf("%d ",mx[i][j]);
      }
    }else{

      printf("[NULL]");
    }

  printf("\n");
  }
return 1;
}
return 0;
}
int** create_mx(int r, int c, int rangeA, int rangeB){

if(r > 0 && c > 0){

size_t row = r;
size_t col = c;

  if(rangeA > rangeB){
    int temp = rangeB;
    rangeB = rangeA;
    rangeA = temp;
  }

  int **mx = (int**)calloc(row, sizeof(int*));

  if(mx){

    for(int i = 0; i < row; i++){

      mx[i] = (int*)calloc(col, sizeof(int));

      if(!mx[i]){

        free_mx(&mx,i);
        i = row;
      }

    }
if((rangeA || rangeB) && mx){
  for(int i = 0; i < row; i++){

      for(int j = 0; j < col; j++){

          mx[i][j] = rand() % (rangeB - rangeA + 1) + rangeA;
          }
    }
}

return mx;
  }

}
return NULL;
}

int **combine_mx(int **mx1, int **mx2, int r1, int c1, int r2, int c2){

if(mx1 && mx2 && r1 > 0 && c1 > 0 && r2 > 0 && c2 > 0){
  size_t row1 = r1;
  size_t col1 = c1;
  size_t row2 = r2;
  size_t col2 = c2;
  size_t new_mx_row = 0;

    if(row1 > row2){

        new_mx_row = row1;
    } else {

        new_mx_row = row2;
    }

  size_t new_mx_col = col1+col2;

  int **new_mx = create_mx(new_mx_row,new_mx_col,0,0);
  if(new_mx){

  for(int i = 0; i < row1; i++){

    for(int j = 0; j < col1; j++){

      if(mx1[i]){

        new_mx[i][j] = mx1[i][j];
      } else {
        new_mx[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < row2; i++){

    for(int j = 0; j < col2; j++){

      if(mx2[i]){

        new_mx[i][col1+j] = mx2[i][j];
      } else {

        new_mx[i][col1+j] = 0;
      }
    }
  }

   return new_mx;
  }

}
return NULL;
}


int main()
{

/*
Необходимо ввести размеры матрицы при выводе и при удалении.
*/

srand(time(0));




int row1 = 5;
int col1 = 5;

int row2 = 5;
int col2 = 5;

int res_row = row2;
if(row1>row2){
res_row = row1;
}
int res_col = col1 + col2;


int **mx1 = create_mx(row1,col1,0,100);
if(!mx1){
printf("couldn't initalize mx1");
return 0;
}

int **mx2 = create_mx(row2,col2,0,100);
if(!mx2){
free_mx(&mx1,row1);
printf("couldn't initalize mx2");
return 0;
}


printf("\n-----------------------------\n\n");
if(!print_mx(mx2,row2,col2)){
printf("failed to print mx2");
}


printf("\n-----------------------------\n\n");
if(!print_mx(res_mx,res_row,res_col)){
printf("failed to print result mx");
}


free_mx(&mx1,row1);
free_mx(&mx2,row2);
free_mx(&res_mx,res_row);

return 0;
}
