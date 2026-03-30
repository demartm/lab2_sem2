#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define Row 15
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
int** create_mx(size_t row, size_t col, int rangeA, int rangeB){

if(row && col){

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

// bool fill_mx(int **mx,size_t row, size_t col,int rangeA, int rangeB){

// if(mx){

//   for(int i = 0; i < row; i++){

//     for(int j = 0; j < col; j++){

//       if(mx[i]){

//         mx[i][j] = rand() % (rangeB + 1) + rangeA;
//       }
//     }
//   }
// return 1;
// }
// return 0;

// }
int** transponse_matrix(int **mx,size_t row, size_t col){

if(mx){

  int **new_mx = create_mx(col,row,0,0);
if(new_mx){
  for(int i = 0; i < row; i++){
if(mx[i]){
    for(int j = 0; j < col; j++){



        new_mx[j][i] = mx[i][j];
      // } else {
      //   new_mx[j][i] = 0;
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

srand(time(0));

int **mx = create_mx(Row,Column,0,100);

if(!mx){
  printf("error initializing matrix");
  return 0;
}

//fill_mx(mx,Row,Column,0,100);
free(mx[1]);
mx[1] = NULL;

if(!print_mx(mx,Row,Column)){
printf("failed to print the matrix");
}

printf("\n-----------------------------\n\n");

int **test = transponse_matrix(mx,Row,Column);
if(!test){
printf("failed to transpose the matrix");
free_mx(&mx,Row);
return 0;
}
if(!print_mx(test,Column,Row)){


printf("failed to print the matrix");
}
free_mx(&mx,Row);
free_mx(&test,Column);

return 0;

}
