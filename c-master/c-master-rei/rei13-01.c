#include <stdio.h>

int global;  //  グローバル変数  

main()
{
  int local;  //  ローカル変数  

  global = 1; //  グローバル変数が使用できる  
  local  = 2;
  { //  新しいブロック  
    int very_local;  //  ブロック内のローカル変数  

     very_local = global + local;
     printf("very_local = %d\n", very_local);  //  使用可  
  }
  printf("very_local = %d\n", very_local);     // 使用不可（エラーとなる） 

  return(0);
}
