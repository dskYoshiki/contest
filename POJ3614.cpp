#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
     
struct Cow{
  int minSPF;
  int maxSPF;
     
  //オーバーロード
  bool operator < (const struct Cow &y) const
  {
    return maxSPF > y.maxSPF;	
  }
  bool operator > (const struct Cow &y) const
  {
    return maxSPF < y.maxSPF;	
  }
};
     
struct Lotion{
  int SPF;
  int bottle;
};
     
void Cswap(struct Cow *x,struct Cow *y){
  struct Cow work;
     
  work = *x;
  *x = *y;
  *y = work;
}
     
void Lswap(struct Lotion *x,struct Lotion *y){
  struct Lotion work;
     
  work = *x;
  *x = *y;
  *y = work;
}
     
int main(){
     
  int C,L;
  int i,j;
  int ans=0;
     
  struct Cow *Cowlist;
  struct Lotion *Lotionlist;
     
  struct Cow now;
     
  scanf("%d %d",&C,&L);
     
  //動的確保
  Cowlist = (struct Cow *)malloc(sizeof(struct Cow)*C);
  Lotionlist = (struct Lotion *)malloc(sizeof(struct Lotion)*L);
     
  //入力
  for(i=0;i<C;i++){
    scanf("%d %d",&Cowlist[i].minSPF ,&Cowlist[i].maxSPF);
  }
  for(i=0;i<L;i++){
    scanf("%d %d",&Lotionlist[i].SPF, &Lotionlist[i].bottle);
  }
     
  //ソート
  for(j=0;j<C-1;j++){
    for(i=0;i<C-1;i++){
      if(Cowlist[i].minSPF > Cowlist[i+1].minSPF){
    	Cswap(&Cowlist[i],&Cowlist[i+1]);
      }
    }
  }
  for(j=0;j<L-1;j++){
    for(i=0;i<L-1;i++){
      if(Lotionlist[i].SPF > Lotionlist[i+1].SPF){
    	Lswap(&Lotionlist[i],&Lotionlist[i+1]);
      }
    }
  }
     
  //プライオリティキュー
  priority_queue<struct Cow,vector<struct Cow>,less<struct Cow> > pq;
     
  //メイン
  i=0;
  for(j=0;j<L;j++){
     
    while(1){	//j番目のボトルを使えない牛を全て取り出す
      if(pq.empty()){
    	break;					//pqが空ならbreak
      }
      now = pq.top();
      if(now.maxSPF < Lotionlist[j].SPF){
    	pq.pop();
      }else{
    	break;					//j番目のボトルを使える牛だけになったらbreak;
      }
    }
     
    while(i<C){
      if(Cowlist[i].minSPF <= Lotionlist[j].SPF){	//j番目のボトルを使える牛を全てpqに格納する
    	pq.push(Cowlist[i]);
    	i++;
      }else{
    	break;
      }
    }
     
    while(Lotionlist[j].bottle > 0){
     
      while(pq.empty()==0){	//j番目のボトルを使えない牛を取り出す
    	now = pq.top();
    	if(now.maxSPF < Lotionlist[j].SPF){
    	  pq.pop();
    	}else{
    	  break;					//j番目のボトルを使える牛になったらbreak;
    	}
      }
     
      if(pq.empty()){
    	Lotionlist[j].bottle = 0;	//ボトルを使える牛がいなければそのボトルを全て捨てる
      }else{
    	pq.pop();		        //ボトルを使える牛がいれば牛を1頭取り出し
    	Lotionlist[j].bottle--;		//ボトルを1本使う
    	ans++;
      }
    }		
  }
     
  //出力
  printf("%d\n",ans);
     
  //メモリ開放
  free(Cowlist);
  free(Lotionlist);
     
  return 0;
}

