#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define Row 5
#define Column 5

/*
 a)Функция объединения двух разреженных  матриц;
*/

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

// if(mx && row && col){

// //bool is_success = true;

//   if(rangeA > rangeB){
//     int temp = rangeB;
//     rangeB = rangeA;
//     rangeA = temp;
//   }

//   for(int i = 0; i < row; i++){
//     if(mx[i]){//rewrite for uncomplete matrix
//       for(int j = 0; j < col; j++){



//           mx[i][j] = rand() % (rangeB - rangeA + 1) + rangeA;

//           // is_success = false;
//           //j = col;
//           }
//       }
//     }
//   return true;}
// return false;
// }



int **combine_mx(int **mx1, int **mx2, size_t row1, size_t col1, size_t row2, size_t col2){

if(mx1 && mx2){

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
      if(mx2[i]){
    for(int j = 0; j < col2; j++){



        new_mx[i][col1+j] = mx2[i][j];
      // } else {

      //   new_mx[i][col1+j] = 0;
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

int **mx1 = create_mx(Row,Column+5,0,100);
if(!mx1){
printf("couldn't initalize mx1");
return 0;
}

int **mx2 = create_mx(Row+5,Column,0,100);
if(!mx2){
free_mx(&mx1,Row);
printf("couldn't initalize mx2");
return 0;
}

int **res_mx = combine_mx(mx1,mx2,Row,Column+5,Row+5,Column);

if(!res_mx){
printf("Invalid pointer!");
free_mx(&mx1,Row);
free_mx(&mx2,Row+5);
return 0;
}

if(!print_mx(mx1,Row,Column+5)){
printf("failed to print mx1");
}

printf("\n-----------------------------\n\n");
if(!print_mx(mx2,Row+5,Column)){
printf("failed to print mx2");
}


printf("\n-----------------------------\n\n");
if(!print_mx(res_mx,Row+5,2*Column+5)){
printf("failed to print result mx");
}



free_mx(&mx1,Row);
free_mx(&mx2,Row+5);
free_mx(&res_mx,Row+5);

return 0;
}
