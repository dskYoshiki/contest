//Warning
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
     
#define limit 1000001
     
void init(bool *HSP){
  for(int i=0;i<limit+1;i++){
    HSP[i] = false;
  }
}
     
void solve_HN(bool *H){
  for(int i=0;i<limit+1;i++){
    if(i%4 == 1 && i!=1){
      H[i] = true;
    }else{
      H[i] = false;
    }
  }
}
     
void solve_HP(bool *H){
  for(int i=1;i<limit+1;i+=4){
    if(H[i]){
      for(int j=i*2;j<limit+1;j+=i){
    	H[j] = false;
      }
    }
  }
}
     
void solve_HSP(bool *H,bool *HSP){
  int bound;
  for(int i=1;i<limit+1;i+=4){
    if(H[i]){
      bound = limit/i;
      for(int j=i;j<=bound;j+=4){
    	if(H[j]){
    	  HSP[i*j] = true;
    	}
      }
    }
  }
}
     
void cnt(bool *HSP,int *ans){
  ans[1]=0;
  for(int i=2;i<limit+1;i++){
    if(i%4 == 1){
      if(HSP[i]){
    	ans[i]=ans[i-4]+1;
      }else{
    	ans[i]=ans[i-4];
      }
    }else{
      ans[i]=ans[i-1];
    }
  }
}
     
int main(){
     
  int N,count;
     
  bool H[limit+1];	//H-number,H-primesの値の保持
  bool HSP[limit+1];	//H-semi-primesの値の保持
  int ans[limit+1];     //H-semi-primesの数の保持
     
  init(HSP);		//配列ansを初期化
  solve_HN(H);		//H-numberを計算して配列Hに入れる
  solve_HP(H);		//H-primesを計算して配列Hに入れる
  solve_HSP(H,HSP);	//H-semi-primesを計算して配列HSPに入れる
  cnt(HSP,ans);
     
  do{
    scanf("%d",&N);		
    if(N!=0){
      printf("%d %d\n",N,ans[N]);
    }		
  }while(N!=0);
     
  return 0;
}

