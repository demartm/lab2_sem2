#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define N 10

void free_mx(int **mx, size_t col){

  if(mx){
    for(int i = 0; i < col; i++){
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
    }else{

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
  int **mx = (int**)calloc(row, sizeof(int*));

  if(mx){

    for(int i = 0; i < row; i++){

      mx[i] = (int*)calloc(col, sizeof(int));

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
      }
    }
  }
return 1;
}
return 0;

}



int main()
{
srand(time(0));

int **mx = init_mx(10,15);
if(!mx){
  printf("error initializing matrix");
  return 0;
}

fill_mx(mx,10,10,0,100);

print_mx(mx,10,15);

free_mx(mx,10);

return 0;
}
