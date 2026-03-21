#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define Row 10
#define Column 10

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

        if(mx[i][j]){

        printf("%d ",mx[i][j]);

        } else {

      printf("0 ");
        }
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
      }
    }
  }
return 1;
}
return 0;

}
int** transponse_matrix(int **mx,size_t row, size_t col){

if(mx){

  int **new_mx = init_mx(row,col);

  for(int i = 0; i < row; i++){

    for(int j = 0; j < col; j++){

      if(mx[i]){

        new_mx[j][i] = mx[i][j];
      } else {
        new_mx[j][i] = 0;
      }
    }
  }

return new_mx;
}
return 0;
}


int main()
{
srand(time(0));
    //printf("Hello World!\n");
//int mx[10][10]={0};
//printf("%d",sizeof(mx)/sizeof(mx[0]));
int **mx = init_mx(Row,Column);
if(!mx){
printf("error initializing matrix");
return 0;
}
//print_mx(mx,10,10);
fill_mx(mx,Row,Column,0,100);
 free(mx[5]);
 mx[5] = NULL;

print_mx(mx,10,10);

printf("\n-----------------------------\n\n");

int **test = transponse_matrix(mx,Row,Column);

return print_mx(test,Row,Column);

    return 0;
}
