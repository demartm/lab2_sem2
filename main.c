#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/*
Общие функции

1. Написать функцию создания динамической матрицы и заполнения ее значениями в заданном диапазоне

2. Написать функцию освобождения памяти динамической матрицы.

3. Написать функцию вывода матрицы на печать.

Индивидуальные задания.
Реализовать следующие функции:

 a)Функция объединения двух разреженных  матриц;

 b)Функция транспонирования разреженной матрицы;
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

void print_mx(int **mx,size_t row,size_t col){

if(mx && row && col){// && r > 0 && c >0){
// size_t row = r;
// size_t col = c;
  for(int i = 0; i < row; i++){

    if(mx[i]){

        for(int j = 0 ; j < col;j++){

          printf("%4d",mx[i][j]);
      }
    }else{

      printf("  [NULL]");
    }

  printf("\n");
  }
//return 1;
}
//return 0;
}

int** create_mx(size_t row, size_t col, int rangeA, int rangeB){

if(row && col){//r > 0 && c > 0){

//size_t row = r;
//size_t col = c;

  if(rangeA > rangeB){
    // int temp = rangeB;
    // rangeB = rangeA;
    // rangeA = temp;

    rangeA ^= rangeB;
    rangeB ^= rangeA;
    rangeA ^= rangeB;
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



int **combine_mx(int **mx1, int **mx2, size_t row1, size_t col1, size_t row2, size_t col2){

if(mx1 && mx2 && row1 && col1 && row2 && col2){// && r1 > 0 && c1 > 0 && r2 > 0 && c2 > 0){
  // size_t row1 = r1;
  // size_t col1 = c1;
  // size_t row2 = r2;
  // size_t col2 = c2;
  size_t new_mx_row = row2;//0;

    if(row1 > row2){

        new_mx_row = row1;
     }// else {

    //     new_mx_row = row2;
    // }

  size_t new_mx_col = col1+col2;

  int **new_mx = create_mx(new_mx_row,new_mx_col,0,0);
  if(new_mx){


for(int i = 0; i < new_mx_row; i++){
  if(mx1[i] || mx2[i]){

    for(int j = 0; j < col1; j++){
      if(mx1[i]){

         new_mx[i][j] = mx1[i][j];
       }
    }

    for(int j = 0; j < col2; j++){
      if(mx2[i]){

        new_mx[i][col1+j] = mx2[i][j];
      }
    }
  } else {

free(new_mx[i]);
new_mx[i] = NULL;
}



}


/*  for(int i = 0; i < row1; i++){

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
*/
   return new_mx;
  }

}
return NULL;
}

int** transpose_matrix(int **mx,size_t row,size_t col){

if(mx && row && col){// r > 0 && c > 0){

  // size_t row = r;
  // size_t col = c;

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

size_t row = 3;
size_t col = 3;

/*Ordnary matrix:

   5   0   2
   4  10   1
   9   6   7*/

// size_t row = 3;
// size_t col = 5;
/*
Ordnary matrix:

   8   4   9   9   3
   8   9   7   7  10
   8  10   8   7   8
*/

// size_t row = 5;
// size_t col = 3;

/*Ordnary matrix:

   1   4   8
   7  10   1
   5   7   5
   2   1   5
   1   5   6*/

// size_t row = 5;
// size_t col = 5;

/*Ordnary matrix:

   7   3   3  10   6
  10   7   7  10   0
   7   4   0   4   2
   4   3   1   4   7
   0   7   6   4   3*/

// int rangeA = 0;
// int rangeB = 10;

// int rangeA = 0;
// int rangeB = 0;

/*Ordnary matrix:

   0   0   0
   0   0   0
   0   0   0*/

// size_t row = 1;
// size_t col = 1;

/*Ordnary matrix:

   2*/

// size_t row = 5;
// size_t col = 1;

/*Ordnary matrix:

   6
   6
   7
   3
   2*/

// size_t row = 1;
// size_t col = 5;

/*Ordnary matrix:

   4   9   2   5   7*/

// size_t row = 1;
// size_t col = 0;
// //error creating matrix

// size_t row = 0;
// size_t col = 1;
// //error creating matrix

// size_t row = 0;
// size_t col = 0;
// //error creating matrix

/*----------------------------------------*/


int rangeA = 10;
int rangeB = 0;

/*Ordnary matrix:

   8   2   5
   8   6   8
  10   8   0*/

/*Ordnary matrix:

   0   1   7
  10   2   8
   4   2   0*/

// int rangeA = -10;
// int rangeB = 0;

/*Ordnary matrix:

  -7  -5  -2
  -2  -3   0
  -9 -10  -5*/

// int rangeA = 0;
// int rangeB = -10;

/*Ordnary matrix:

  -8  -9  -6
  -6  -7  -4
   0  -8  -4*/

// int rangeA = 1;
// int rangeB = 1;

/*Ordnary matrix:

   1   1   1
   1   1   1
   1   1   1*/


/*----------------------------------------*/




printf("\n-----------------------------\nOrdnary matrix:\n\n");

int **mx0 = create_mx(row,col,rangeA, rangeB);


// int **mx0 = create_mx(0,col,rangeA, rangeB);
//error creating matrix

//int **mx0 = create_mx(row,0,rangeA, rangeB);
//error creating matrix

//int **mx0 = create_mx(0,0,rangeA, rangeB);
//error creating matrix

// int **mx0 = create_mx(0,col,rangeA, rangeB);
// //error creating matrix

//int **mx0 = create_mx(-1,col,rangeA, rangeB);
//error creating matrix

// int **mx0 = create_mx(row,-1,rangeA, rangeB);
// //error creating matrix

// int **mx0 = create_mx(-1,-1,rangeA, rangeB);
// //error creating matrix

// int **mx0 = create_mx(100000000000,col,rangeA, rangeB);
// //error creating matrix

//int **mx0 = create_mx(row,10000000000000000000000000,rangeA, rangeB);
// //error creating matrix

// free(mx0[1]);
// mx0[1] = NULL;
/*Ordnary matrix:

  10   0   0
  [NULL]
   4   1   5*/

if(!mx0){
  printf("error creating matrix");
  return 0;
}
print_mx(mx0,row,col);

free_mx(&mx0,row);

//free_mx(mx0,row);
//free_mx(NULL,row);

//return 0;




size_t row1 = 3;
size_t col1 = 3;

size_t row2 = 3;
size_t col2 = 3;

/*Matrix1:

   1   9   5
   7   9   5
  10   8  10

-----------------------------
Matrix2:

   0   3   4
   0   1   4
   3   3  10

-----------------------------
Mx1 and Mx2 combined:

   1   9   5   0   3   4
   7   9   5   0   1   4
  10   8  10   3   3  10*/

// size_t row1 = 6;
// size_t col1 = 3;

// size_t row2 = 3;
// size_t col2 = 6;

/*Matrix1:

   7   2   3
   5   4   9
   6   3   9
   0   0   4
   0   7   3
   6   8   8

-----------------------------
Matrix2:

  10   2   6   2   3   5
   4   2   0   7  10   3
   0   6   5   1  10   7

-----------------------------
Mx1 and Mx2 combined:

   7   2   3  10   2   6   2   3   5
   5   4   9   4   2   0   7  10   3
   6   3   9   0   6   5   1  10   7
   0   0   4   0   0   0   0   0   0
   0   7   3   0   0   0   0   0   0
   6   8   8   0   0   0   0   0   0*/

// size_t row1 = 3;
// size_t col1 = 6;

// size_t row2 = 6;
// size_t col2 = 3;

/*Matrix1:

   4   0   0   1   9   9
   0   1   5   6  10   6
   9   5   5  10   1   2

-----------------------------
Matrix2:

   7   5  10
   2   6   7
   0   9   1
   1   5   1
   7   9  10
   5   9   8

-----------------------------
Mx1 and Mx2 combined:

   4   0   0   1   9   9   7   5  10
   0   1   5   6  10   6   2   6   7
   9   5   5  10   1   2   0   9   1
   0   0   0   0   0   0   1   5   1
   0   0   0   0   0   0   7   9  10
   0   0   0   0   0   0   5   9   8*/

// size_t row1 = 6;
// size_t col1 = 3;

// size_t row2 = 6;
// size_t col2 = 3;

/*Matrix1:

   8   5   4
   8   5   9
   1   4   1
   3   3   0
   6   1   0
   4   3   4

-----------------------------
Matrix2:

   7   6   1
   5   6   6
   3   0   7
   4   1  10
   2  10   4
   4   7  10

-----------------------------
Mx1 and Mx2 combined:

   8   5   4   7   6   1
   8   5   9   5   6   6
   1   4   1   3   0   7
   3   3   0   4   1  10
   6   1   0   2  10   4
   4   3   4   4   7  10*/

// size_t row1 = 3;
// size_t col1 = 6;

// size_t row2 = 3;
// size_t col2 = 6;

/*Matrix1:

   4   1   0   3   9   3
   9   6   6   7   2   8
   3   0   9   1   1   3

-----------------------------
Matrix2:

   8   5   3   3   3   9
   1   1   3   2   5   4
   9   8   5   7   0   2

-----------------------------
Mx1 and Mx2 combined:

   4   1   0   3   9   3   8   5   3   3   3   9
   9   6   6   7   2   8   1   1   3   2   5   4
   3   0   9   1   1   3   9   8   5   7   0   2*/

// size_t row1 = 1;
// size_t col1 = 1;

// size_t row2 = 1;
// size_t col2 = 1;

/*Matrix1:

   5

-----------------------------
Matrix2:

   2

-----------------------------
Mx1 and Mx2 combined:

   5   2*/


int **mx1 = create_mx(row1,col1,rangeA, rangeB);
if(!mx1){
  printf("error creating matrix");
  return 0;
}


int **mx2 = create_mx(row2,col2,rangeA, rangeB);

if(!mx1){
  printf("error creating matrix");
  free_mx(&mx1,row1);
  return 0;
}

// free(mx1[1]);
// mx1[1] = NULL;

// free(mx2[1]);
// mx2[1] = NULL;


/*Mx1 and Mx2 combined:

   3   8   9   2   5   4
  [NULL]
   3   7   3   4   3   7*/

free(mx1[0]);
mx1[0] = NULL;

free(mx1[1]);
mx1[1] = NULL;

free(mx1[2]);
mx1[2] = NULL;

free(mx2[0]);
mx2[0] = NULL;

free(mx2[1]);
mx2[1] = NULL;

free(mx2[2]);
mx2[2] = NULL;


/*Matrix2:

  [NULL]
  [NULL]
  [NULL]

-----------------------------
Mx1 and Mx2 combined:

  [NULL]
  [NULL]
  [NULL]

-----------------------------
Comb_mx transposed:

   0   0   0
   0   0   0
   0   0   0
   0   0   0
   0   0   0
   0   0   0*/




// free(mx1[1]);
// mx1[1] = NULL;

/*Matrix1:

   9   8   2
  [NULL]
   3   2   5

-----------------------------
Matrix2:

  10   5   6
   2   4   7
   4   4   5

-----------------------------
Mx1 and Mx2 combined:

   9   8   2  10   5   6
   0   0   0   2   4   7
   3   2   5   4   4   5*/


// free(mx1[1]);
// mx1[1] = NULL;

// free(mx2[2]);
// mx2[2] = NULL;

/*Matrix1:

   5   1  10
  [NULL]
   3   4   8

-----------------------------
Matrix2:

  10   8   8
   9   6   1
  [NULL]

-----------------------------
Mx1 and Mx2 combined:

   5   1  10  10   8   8
   0   0   0   9   6   1
   3   4   8   0   0   0*/

// free(mx1[0]);
// mx1[0] = NULL;

// free(mx1[1]);
// mx1[1] = NULL;

// free(mx1[2]);
// mx1[2] = NULL;

/*Matrix1:

  [NULL]
  [NULL]
  [NULL]

-----------------------------
Matrix2:

   6   4   1
   2   9   3
   4   5   7

-----------------------------
Mx1 and Mx2 combined:

   0   0   0   6   4   1
   0   0   0   2   9   3
   0   0   0   4   5   7*/




printf("\n-----------------------------\nMatrix1:\n\n");

print_mx(mx1,row1,col1);

printf("\n-----------------------------\nMatrix2:\n\n");

print_mx(mx2,row2,col2);


int **comb_mx = combine_mx(mx1,mx2,row1,col1,row2,col2);

// int **comb_mx = combine_mx(NULL,mx2,row1,col1,row2,col2);
// //error creating matrix

// int **comb_mx = combine_mx(mx1,NULL,row1,col1,row2,col2);
// //error creating matrix

// int **comb_mx = combine_mx(NULL,NULL,row1,col1,row2,col2);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,0,col1,row2,col2);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,row1,0,row2,col2);
// //error creating matrix

// int **comb_mx = combine_mx(mx1,mx2,row1,col1,0,col2);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,0,0,0,0);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,-1,col1,-1,col2);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,row1,-1,row2,-1);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,-1,-1,-1,-1);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,10000000000000000000,col1,row2,col2);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,row1,100000000000000000000000,row2,col2);
// //error creating matrix

//int **comb_mx = combine_mx(mx1,mx2,row1,col1,10000000000000000000,col2);
// //error creating matrix

//  int **comb_mx = combine_mx(mx1,mx2,row1,col1,row2,10000000000000000000);
// //error creating matrix

if(!comb_mx){
  printf("error creating matrix");
  free_mx(&mx1,row1);
  free_mx(&mx2,row2);
  return 0;

}

/*----------------------------------------*/


size_t comb_col = col1 + col2;
size_t comb_row = row1;

if(row2> row1){
  comb_row= row2;
}

printf("\n-----------------------------\nMx1 and Mx2 combined:\n\n");
print_mx(comb_mx,comb_row,comb_col);

free_mx(&mx1,row1);
free_mx(&mx2,row2);


/*----------------------------------------*/


// free(comb_mx[1]);
// comb_mx[1] = NULL;
/*Matrix1:

   7   5   0
   8   4   0
  10  10   4

-----------------------------
Matrix2:

   0   9   8
   6   2   3
   4   5   3

-----------------------------
Mx1 and Mx2 combined:

   7   5   0   0   9   8
   8   4   0   6   2   3
  10  10   4   4   5   3

-----------------------------
Comb_mx transposed:

   7   0  10
   5   0  10
   0   0   4
   0   0   4
   9   0   5
   8   0   3*/


int **transposed_comb = transpose_matrix(comb_mx,comb_row,comb_col);
if(!transposed_comb){
  printf("error creating matrix");
  free_mx(&comb_mx,comb_row);
  return 0;
}

printf("\n-----------------------------\nComb_mx transposed:\n\n");
print_mx(transposed_comb,comb_col,comb_row);

/*Matrix1:

   5   0   9
   9   9   9
   7   1   1

-----------------------------
Matrix2:

   7   6   2
   2  10   9
  10   7   3

-----------------------------
Mx1 and Mx2 combined:

   5   0   9   7   6   2
   9   9   9   2  10   9
   7   1   1  10   7   3

-----------------------------
Comb_mx transposed:

   5   9   7
   0   9   1
   9   9   1
   7   2  10
   6  10   7
   2   9   3*/

free_mx(&comb_mx,comb_row);
free_mx(&transposed_comb,comb_col);


/*----------------------------------------*/

size_t row3 = 3;
size_t col3 = 3;

/*Matrix3:

   7   5   7
   1   3   4
   5   8  10

-----------------------------
Matrix3 transposed:

   7   1   5
   5   3   8
   7   4  10*/

// size_t row3 = 3;
// size_t col3 = 5;

/*/*Matrix3:

   7   5   7
   1   3   4
   5   8  10

-----------------------------
Matrix3 transposed:

   7   1   5
   5   3   8
   7   4  10*/

// size_t row3 = 5;
// size_t col3 = 3;

/*Matrix3:

   1   1  10
   0   2   4
   1   0   3
   5   5   6
   0   3   1

-----------------------------
Matrix3 transposed:

   1   0   1   5   0
   1   2   0   5   3
  10   4   3   6   1*/

// size_t row3 = 3;
// size_t col3 = 1;

/*Matrix3:

   8
   7
   8

-----------------------------
Matrix3 transposed:

   8   7   8*/

int **mx3 = create_mx(row3,col3,rangeA,rangeB);
if(!mx3){
  printf("error creating matrix");
  return 0;
}

// free(mx3[1]);
// mx3[1] = NULL;

/*Matrix3:

   8   2   6
  [NULL]
  10  10   2

-----------------------------
Matrix3 transposed:

   8   0  10
   2   0  10
   6   0   2*/

free(mx3[1]);
mx3[1] = NULL;

free(mx3[2]);
mx3[2] = NULL;

/*Matrix3:

  10   8   8
  [NULL]
  [NULL]

-----------------------------
Matrix3 transposed:

  10   0   0
   8   0   0
   8   0   0*/

printf("\n-----------------------------\nMatrix3:\n\n");
print_mx(mx3,row3,col3);

int **mx3_t = transpose_matrix(mx3,row3,col3);
if(!mx3_t){
  printf("error creating matrix");
  free_mx(&mx3,row3);
  return 0;
}

printf("\n-----------------------------\nMatrix3 transposed:\n\n");
print_mx(mx3_t,col3,row3);

free_mx(&mx3,row3);
free_mx(&mx3_t,col3);

return 0;
}
