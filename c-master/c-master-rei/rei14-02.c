#include <stdio.h>
      
void proc( int a );  // 関数プロトタイプ宣言 
void dummy( void );  // 関数プロトタイプ宣言 
      
main()
{
  proc(1);  // １回目の呼び出し 
  dummy();  // 何もしないダミー関数 
  proc(2);  // ２回目の呼び出し 
      
  return(0);
}
      
void proc( int a )
{
  int b;  // ローカル変数宣言（初期化していないので値は不明） 
        
  printf("a = %d, b = %d\n", a, b);

  a = 12;
  b = 10;

  return;
}
      
void dummy( void )
{
  int s[100], i;

  for (i = 0; i < 100; i++) {
    s[i] = i;
  }

  return;
}
