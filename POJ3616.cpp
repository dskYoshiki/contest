//エラー
#include <stdio.h>
#include <stdlib.h>
     
void swap(int *x,int *y){
  int work;
  work = *x;
  *x = *y;
  *y = work;
}
     
int main(){
  int N,M,R;
  int i,j;
     
  scanf("%d",&N);
  scanf("%d",&M);
  scanf("%d",&R);
     
  int *Mlist,*Ntime;
  Mlist = malloc(sizeof(int)*M*3);
  Ntime = malloc(sizeof(int)*(N+1));
     
  for(i=0;i<M*3;i++){
    scanf("%d",&Mlist[i]);
  }
     
  //バブルソート
  for(i=0;i<M;i++){
    for(j=0;j<M-1;j++){
      if(Mlist[3*j+1] > Mlist[3*(j+1)+1]){
    	swap(&Mlist[3*j],&Mlist[3*(j+1)]);
    	swap(&Mlist[3*j+1],&Mlist[3*(j+1)+1]);
    	swap(&Mlist[3*j+2],&Mlist[3*(j+1)+2]);
      }
    }
  }
     
  //動的計画法
  Ntime[0] = 0;
  j=0;
  for(i=1;i<=N;i++){
    Ntime[i] = Ntime[i-1];
    while(Mlist[3*j+1] == i && j<M){
      if(Ntime[i] <= Mlist[3*j+2]){//初めてミルクをとる場合
    	Ntime[i] = Mlist[3*j+2];
      }
      if(Mlist[3*j]-R >= 0){  //error回避
    	if(Ntime[i] <= (Ntime[Mlist[3*j]-R])+Mlist[3*j+2]){//休憩を挟んで2回目以降のミルクをとる場合
    	  Ntime[i] = (Ntime[Mlist[3*j]-R])+Mlist[3*j+2];
    	}
      }
      j++;
    }
  }
     
  printf("%d\n",Ntime[N]);
     
  free(Mlist);
  free(Ntime);
     
  return 0;
     
}

