#include <stdio.h>

int main()
{
  int j, i;       // iはクラスの番号, aaaは学年の番号  

  int rows;
  int cols;

  int zaiseki[4][9] = {
    {41,40,40,40,40,41,41,42,0},   
    {39,38,34,40,37,39,35,39,0},   
    {30,39,31,40,38,40,33,36,0},   
    {0,0,0,0,0,0,0,0,0}            
  };

  rows = sizeof(zaiseki) / sizeof(zaiseki[0]) - 1;
  cols = sizeof(zaiseki[0]) / sizeof(zaiseki[0][0]) - 1;

  // printf("rows:%d\ncols:%d\n", rows, cols);
  
  for (i = 0; i < rows; i ++) {
    for (j = 0; j < cols; j ++) {
      zaiseki[i][cols] += zaiseki[i][j];
      zaiseki[rows][j] += zaiseki[i][j];
    }
  }

  for (i = 0; i < rows; i ++) {
    printf("%d年生の生徒数は %d人です。\n", i + 1, zaiseki[i][cols]);
  }

  for (i = 0; i < cols; i ++) {
    printf("%d組の生徒数は %d人です。\n", i + 1, zaiseki[rows][i]);
  }

  return(0);
}
