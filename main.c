#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define N 10

/*
Общие функции

1. Написать функцию создания динамической матрицы и заполнения ее значениями в заданном диапазоне

2. Написать функцию освобождения памяти динамической матрицы.

3. Написать функцию вывода матрицы на печать.
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

//}



int main()
{
srand(time(0));

//int **mx = create_mx(0,0,0,100);
//Вывод:error initializing matrix

//int **mx = create_mx(10,0,0,100);
//Вывод:error initializing matrix

//int **mx = create_mx(0,10,0,100);
//Вывод:error initializing matrix

//int **mx = create_mx(-10,10,0,100);
//Вывод:error initializing matrix

//int **mx = create_mx(10,-10,0,100);
//Вывод:error initializing matrix

/*
Необходимо ввести размеры матрицы при выводе и при удалении.
*/

//int **mx = create_mx(10,10,0,0);
//Вывод:
/*0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0*/

//int **mx = create_mx(4,4,10,0);
//Вывод:
/*
10 5 2 6
4 0 4 1
7 4 8 9
4 0 2 7
*/

//int **mx = create_mx(4,4,0,10);
//Вывод:
/*
9 5 4 0
5 0 6 9
7 10 2 7
10 4 6 4
*/

//int **mx = create_mx(4,4,0,-10);
//Вывод:
/*
-5 -8 -5 -5
-7 -7 -5 -5
-10 -6 0 -10
-5 -8 -3 -2
*/

//int **mx = create_mx(4,4,-10,0);
//Вывод:
/*
-8 -8 -9 0
-5 -8 -8 -1
-6 -3 -3 0
-10 -6 -5 0
*/

//int **mx = create_mx(4,10,0,10);
//Вывод:
/*
3 8 6 1 10 0 9 4 6 4
0 2 2 3 2 1 6 3 4 3
4 3 7 1 0 1 5 9 3 1
7 6 9 0 5 6 0 4 10 4
*/

//int **mx = create_mx(10,4,0,10);
//Вывод:
/*
2 0 5 2
8 1 8 2
2 7 5 1
1 3 1 6
8 4 0 1
6 0 6 9
5 1 10 1
8 1 6 8
1 0 0 7
0 8 10 2
*/

int **mx = create_mx(4,4,0,10);
if(!mx){
  printf("error initializing matrix");
  return 0;
}
//free(mx[2]);
//mx[2] = NULL;
/*
6 6 6 8
0 1 2 5
[NULL]
0 7 5 3
*/
// free(mx[3]);
// mx[3] = NULL;
/*
10 3 2 9
7 3 4 1
10 3 10 8
[NULL]
*/


//if(!print_mx(NULL,4,4)){
//Вывод:failed to print the matrix

//if(!print_mx(mx,0,4)){
//Вывод:failed to print the matrix

//if(!print_mx(mx,4,0)){
//Вывод:failed to print the matrix

//if(!print_mx(mx,-4,4)){
//Вывод:failed to print the matrix

//if(!print_mx(mx,4,-4)){
//Вывод:failed to print the matrix

//if(!print_mx(mx,-4,-4)){
//Вывод:failed to print the matrix

if(!print_mx(mx,4,4)){
printf("failed to print the matrix");
}

free_mx(&mx,4);

return 0;
}
