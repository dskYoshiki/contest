#include <stdio.h>
#include <stdlib.h>
#include <time.h>
     
typedef struct{
  int D;
  int T;
}TEST;
     
int comp1( const void *c1, const void *c2 );
int comp2( const void *c1, const void *c2 );
     
int main(void)
{
  int i;
  int N;//牛の数
  int sumD=0;//Dの和
  int answer=0;
  TEST base[10];
     
  scanf("%d",&N);
  for( i=0; i<N; i++ ){
    scanf("%d%d",&base[i].T,&base[i].D); 
    sumD=sumD+base[i].D;
  }
     
  qsort( base, N, sizeof(TEST), comp1 );
  qsort( base, N, sizeof(TEST), comp2 );
     
  for( i=0; i<N; i++ ){
    sumD=sumD-base[i].D;
    answer=answer+sumD*2*base[i].T;
  }
  printf( "answer=>%d\n",answer);
  return 0;
}
     
/* 比較関数 */
int comp2( const void *c1, const void *c2 )
{
  TEST test1 = *(TEST *)c1;
  TEST test2 = *(TEST *)c2;
     
  int tmp1 = test1.D;   /* Dを基準とする */
  int tmp2 = test2.D;
     
  return tmp2 - tmp1;
}
     
int comp1( const void *c1, const void *c2 )
{
  TEST test1 = *(TEST *)c1;
  TEST test2 = *(TEST *)c2;
     
  int tmp1 = test1.T;   /* Tを基準とする */
  int tmp2 = test2.T;
     
  return tmp1 - tmp2;
}

