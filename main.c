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




// int row1 = 4;
// int col1 = 9;

// int row2 = 4;
// int col2 = 4;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*
87 74 42 45 58 85 73 3 94
63 100 83 43 20 34 64 91 66
42 48 39 84 42 24 89 25 62
54 94 20 44 80 94 53 25 18

-----------------------------

3 98 88 97
26 87 45 35
6 45 65 64
11 6 11 16

-----------------------------

87 74 42 45 58 85 73 3 94 3 98 88 97
63 100 83 43 20 34 64 91 66 26 87 45 35
42 48 39 84 42 24 89 25 62 6 45 65 64
54 94 20 44 80 94 53 25 18 11 6 11 16
*/



// int row1 = 4;
// int col1 = 9;

// int row2 = 9;
// int col2 = 4;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*
37 8 21 89 80 54 37 72 59
36 51 34 70 86 3 18 84 14
37 77 12 97 58 6 99 82 68
90 45 41 67 83 49 55 37 96

-----------------------------

8 74 67 33
10 18 34 80
3 3 65 54
84 68 97 97
64 20 69 29
68 36 85 13
77 52 62 93
73 99 88 47
38 54 80 14

-----------------------------

37 8 21 89 80 54 37 72 59 8 74 67 33
36 51 34 70 86 3 18 84 14 10 18 34 80
37 77 12 97 58 6 99 82 68 3 3 65 54
90 45 41 67 83 49 55 37 96 84 68 97 97
0 0 0 0 0 0 0 0 0 64 20 69 29
0 0 0 0 0 0 0 0 0 68 36 85 13
0 0 0 0 0 0 0 0 0 77 52 62 93
0 0 0 0 0 0 0 0 0 73 99 88 47
0 0 0 0 0 0 0 0 0 38 54 80 14
*/


// int row1 = 9;
// int col1 = 4;

// int row2 = 4;
// int col2 = 9;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*
11 54 78 9
92 65 53 59
4 87 41 22
89 35 56 4
23 16 67 74
90 62 80 75
81 5 56 18
69 72 77 46
25 20 56 16

-----------------------------

85 8 41 89 61 48 10 16 83
32 87 6 49 54 46 4 82 93
79 28 98 34 47 33 5 23 79
97 43 34 79 28 9 86 83 36

-----------------------------

11 54 78 9 85 8 41 89 61 48 10 16 83
92 65 53 59 32 87 6 49 54 46 4 82 93
4 87 41 22 79 28 98 34 47 33 5 23 79
89 35 56 4 97 43 34 79 28 9 86 83 36
23 16 67 74 0 0 0 0 0 0 0 0 0
90 62 80 75 0 0 0 0 0 0 0 0 0
81 5 56 18 0 0 0 0 0 0 0 0 0
69 72 77 46 0 0 0 0 0 0 0 0 0
25 20 56 16 0 0 0 0 0 0 0 0 0
*/


// int row1 = 9;
// int col1 = 4;

// int row2 = 9;
// int col2 = 4;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*20 74 86 59
59 98 11 69
73 80 18 74
27 39 24 31
42 24 41 6
99 61 89 33
65 13 18 70
54 21 42 40
61 27 99 86

-----------------------------

92 10 54 30
56 72 3 49
78 95 80 86
85 88 58 84
14 46 16 46
59 0 15 12
22 57 18 49
50 16 35 7
93 55 37 15

-----------------------------

20 74 86 59 92 10 54 30
59 98 11 69 56 72 3 49
73 80 18 74 78 95 80 86
27 39 24 31 85 88 58 84
42 24 41 6 14 46 16 46
99 61 89 33 59 0 15 12
65 13 18 70 22 57 18 49
54 21 42 40 50 16 35 7
61 27 99 86 93 55 37 15*/


// int row1 = 4;
// int col1 = 9;

// int row2 = 4;
// int col2 = 9;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*
72 52 22 3 23 70 53 67 78
14 3 46 82 79 47 1 68 57
39 100 78 71 57 42 44 30 26
7 76 44 47 13 63 70 17 52

-----------------------------

5 36 18 49 16 88 95 99 66
41 66 0 65 5 100 42 42 56
51 87 86 77 60 27 88 73 41
50 8 24 1 80 60 86 28 76

-----------------------------

72 52 22 3 23 70 53 67 78 5 36 18 49 16 88 95 99 66
14 3 46 82 79 47 1 68 57 41 66 0 65 5 100 42 42 56
39 100 78 71 57 42 44 30 26 51 87 86 77 60 27 88 73 41
7 76 44 47 13 63 70 17 52 50 8 24 1 80 60 86 28 76
*/


// int row1 = 4;
// int col1 = 4;

// int row2 = 4;
// int col2 = 4;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*
95 29 94 70
69 77 44 28
31 15 43 8
23 12 86 34

-----------------------------

26 4 82 39
29 32 54 5
81 12 28 22
11 82 5 5

-----------------------------

95 29 94 70 26 4 82 39
69 77 44 28 29 32 54 5
31 15 43 8 81 12 28 22
23 12 86 34 11 82 5 5
*/

// int row1 = 1;
// int col1 = 1;

// int row2 = 1;
// int col2 = 1;

// int res_row = row2;
// if(row1>row2){
// res_row = row1;
// }
// int res_col = col1 + col2;

/*
4

-----------------------------

98

-----------------------------

4 98
*/

int row1 = 5;
int col1 = 5;

int row2 = 5;
int col2 = 5;

int res_row = row2;
if(row1>row2){
res_row = row1;
}
int res_col = col1 + col2;



//int **mx1 = create_mx(0,100,0,100);
//Вывод:couldn't initalize mx1

//int **mx1 = create_mx(100,0,0,100);
//Вывод:couldn't initalize mx1

//int **mx1 = create_mx(0,0,0,100);
//Вывод:couldn't initalize mx1

/*int **mx1 = create_mx(row1,col1,10,0);
if(!mx1){
printf("couldn't initalize mx1");
return 0;
}
print_mx(mx1,row1,col1);
free_mx(&mx1,Row);
return 0;*/
//Вывод:
/*
6 7 9 6 8
0 2 8 2 0
5 3 2 5 5
0 8 7 0 4
5 6 7 0 7 */

//
/*int **mx1 = create_mx(row1,col1,0,10);
if(!mx1){
printf("couldn't initalize mx1");
return 0;
}
print_mx(mx1,row1,col1);
free_mx(&mx1,row1);
return 0;*/
//Вывод:
/*
7 7 0 4 5
4 6 4 5 10
4 10 8 10 0
1 5 1 7 2
7 10 9 2 0*/


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

// free(mx1[1]);
// mx1[1] = NULL;

/*
14 3 15 16 15
[NULL]
8 71 47 45 38
71 43 36 43 68
67 3 67 58 50

-----------------------------

88 98 57 38 59
67 53 62 82 35
44 41 31 72 89
71 80 60 84 25
64 21 34 67 64

-----------------------------

14 3 15 16 15 88 98 57 38 59
0 0 0 0 0 67 53 62 82 35
8 71 47 45 38 44 41 31 72 89
71 43 36 43 68 71 80 60 84 25
67 3 67 58 50 64 21 34 67 64
*/

// free(mx2[1]);
// mx2[1] = NULL;

/*
64 7 84 100 66
25 53 27 20 38
73 37 71 88 73
53 49 3 18 57
93 48 0 6 93

-----------------------------

45 0 22 22 73
[NULL]
11 15 70 39 35
7 78 38 44 65
10 97 80 80 81

-----------------------------

64 7 84 100 66 45 0 22 22 73
25 53 27 20 38 0 0 0 0 0
73 37 71 88 73 11 15 70 39 35
53 49 3 18 57 7 78 38 44 65
93 48 0 6 93 10 97 80 80 81
*/

// free(mx2[1]);
// mx2[1] = NULL;
// free(mx1[1]);
// mx1[1] = NULL;

/*77 58 20 11 19
[NULL]
74 28 99 39 46
53 77 39 43 97
16 32 67 73 67

-----------------------------

91 44 60 44 49
[NULL]
93 13 98 27 43
40 1 72 4 6
84 57 83 89 100

-----------------------------

77 58 20 11 19 91 44 60 44 49
0 0 0 0 0 0 0 0 0 0
74 28 99 39 46 93 13 98 27 43
53 77 39 43 97 40 1 72 4 6
16 32 67 73 67 84 57 83 89 100*/

free(mx2[2]);
mx2[2] = NULL;
free(mx1[1]);
mx1[1] = NULL;

/*45 81 25 10 34
[NULL]
54 23 70 59 23
99 52 94 53 94
48 74 39 53 28

-----------------------------

84 78 91 61 96
100 73 42 25 83
[NULL]
70 1 25 39 26
48 38 78 8 91

-----------------------------

45 81 25 10 34 84 78 91 61 96
0 0 0 0 0 100 73 42 25 83
54 23 70 59 23 0 0 0 0 0
99 52 94 53 94 70 1 25 39 26
48 74 39 53 28 48 38 78 8 91 */
//int **res_mx = combine_mx(NULL,mx2,row1,col1,row2,col2);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,NULL,row1,col1,row2,col2);
//failed to print result matrix

//int **res_mx = combine_mx(NULL,NULL,row1,col1,row2,col2);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,mx2,0,col1,row2,col2);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,mx2,row1,0,row2,col2);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,mx2,row1,col1,-1,col2);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,mx2,row1,col1,row2,-1);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,mx2,0,0,0,0);
//failed to print result matrix

//int **res_mx = combine_mx(mx1,mx2,-1,-1,-1,-1);
//failed to print result matrix

int **res_mx = combine_mx(mx1,mx2,row1,col1,row2,col2);

if(!res_mx){
printf("failed to print result matrix");
free_mx(&mx1,row1);
free_mx(&mx2,row2);
return 0;
}
if(!print_mx(mx1,row1,col1)){
//if(!print_mx(mx1,row1,col1)){
printf("failed to print mx1");
}



/*if(!print_mx(mx1,row1,0)){
 * failed to print mx1
-----------------------------

92 71 59 71 15
43 36 21 45 17
[NULL]
95 89 32 0 86
1 79 38 68 43

-----------------------------

65 40 1 82 41 92 71 59 71 15
0 0 0 0 0 43 36 21 45 17
96 96 40 98 70 0 0 0 0 0
78 86 100 65 35 95 89 32 0 86
47 91 89 42 71 1 79 38 68 43*/

/*
 * if(!print_mx(mx1,0,col1)){
 * failed to print mx1
-----------------------------

74 100 58 21 95
10 27 17 35 29
[NULL]
59 66 54 73 78
3 4 55 3 27

-----------------------------

40 23 25 2 74 74 100 58 21 95
0 0 0 0 0 10 27 17 35 29
1 9 48 45 49 0 0 0 0 0
65 11 34 23 37 59 66 54 73 78
96 49 21 16 25 3 4 55 3 27 */
/*
 if(!print_mx(NULL,row1,col1)){
failed to print mx1
-----------------------------

72 7 31 2 87
84 82 56 43 19
[NULL]
67 4 53 76 20
21 69 42 45 77

-----------------------------

79 3 94 72 11 72 7 31 2 87
0 0 0 0 0 84 82 56 43 19
94 8 8 16 69 0 0 0 0 0
27 56 58 8 41 67 4 53 76 20
31 73 35 5 59 21 69 42 45 77*/

printf("\n-----------------------------\n\n");
if(!print_mx(mx2,row2,col2)){
printf("failed to print mx2");
}


printf("\n-----------------------------\n\n");
if(!print_mx(res_mx,res_row,res_col)){
printf("failed to print result mx");
}

/*
Количество строк = максимальному среди объединяемых массивов
*/

free_mx(&mx1,row1);
free_mx(&mx2,row2);
free_mx(&res_mx,res_row);

return 0;
}
