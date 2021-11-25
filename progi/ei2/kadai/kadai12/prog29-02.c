#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>

void printCombi(int n, int r);
void printCombiRec(int n, int r, int p, int s, int sel[]);
void printSelected(int sel[], int n);

int main(int argc, char *argv[])
{
  int n, r;

  if (argc < 3) {
    fprintf(stderr, "第1引数にnを、第2引数にrを指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &r);

  printCombi(n, r);

  return(0);
}

void printCombi(int n, int r)
{
  int sel[100];

  printCombiRec(n , r , 0 , 0 , sel);
}

void printCombiRec(int n, int r, int p, int s, int sel[])
{

}

void printSelected(int sel[], int n)
{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", sel[i]);
  }
  printf("\n");

  return;
}
