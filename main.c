#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define Row 5
#define Column 5

void free_mx(int **mx, size_t row){

if(mx){

  for(int i = 0; i < row; i++){

    free(mx[i]);
    mx[i] = NULL;
  }

free(mx);
mx = NULL;
}

}


bool print_mx(int **mx,size_t row,size_t col){

  if(mx){

    for(int i = 0; i < row; i++){

      if(mx[i]){

          for(int j = 0 ; j < col;j++){
            printf("%d ",mx[i][j]);
          }

      } else {
      printf("[NULL]");
      }

    printf("\n");
    }
  return 1;
  }
return 0;

}
int** init_mx(size_t row, size_t col){

if(row && col){

  int **mx = (int**)malloc(row*sizeof(int*));

  if(mx){

    for(int i = 0; i < row; i++){

      mx[i] = (int*)malloc(col*sizeof(int));

      if(!mx[i]){

        free_mx(mx,i);
        i = row;
      }

    }

  } else {
    free(mx);
    }

return mx;
}
return 0;
}

bool fill_mx(int **mx,size_t row, size_t col,int rangeA, int rangeB){

if(mx){

  for(int i = 0; i < row; i++){

    for(int j = 0; j < col; j++){

      if(mx[i]){

        mx[i][j] = rand() % (rangeB + 1) + rangeA;
      }//clean
    }
  }
return 1;
}
return 0;

}

int **combine_mx(int **mx1, int **mx2, size_t row1, size_t col1, size_t row2, size_t col2){

size_t new_mx_row = 0;
if(row1 > row2){
  new_mx_row = row1;
} else {
  new_mx_row = row2;
}

size_t new_mx_col = col1+col2;

int **new_mx = init_mx(new_mx_row,new_mx_col);

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


int main()
{
srand(time(0));

int **mx1 = init_mx(Row,Column+5);
int **mx2 = init_mx(Row+5,Column);


fill_mx(mx1,Row,Column+5,0,100);

fill_mx(mx2,Row+5,Column,0,100);
int **mx3 = combine_mx(mx1,mx2,Row,Column+5,Row+5, Column);

print_mx(mx1,Row,Column+5);
printf("\n-----------------------------\n\n");

print_mx(mx2,Row+5,Column);
printf("\n-----------------------------\n\n");

print_mx(mx3,Row+5,Column+Column+5);
free_mx(mx1,Row);
free_mx(mx2,Row+5);

free_mx(mx3,Row+5);

    return 0;
}
