#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
     
using namespace std;
     
struct Road{//AからBへの長さがLである道
     
  int A,B,L;
     
  //オーバーロード
  bool operator < (const struct Road &y) const
  {
    return L < y.L;	
  }
  bool operator > (const struct Road &y) const
  {
    return L > y.L;	
  }
     
};
     
int main(){
     
  int N,M,ans;
  int i,j;
     
  bool *Farmlist;
  struct Road *Roadlist;
     
  scanf("%d %d",&N,&M);
     
  //動的確保
  Farmlist = (bool *)malloc(sizeof(bool)*(N+1));
  Roadlist = (struct Road *)malloc(sizeof(struct Road)*M);
     
  //入力
  for(i=0;i<M;i++){
    scanf("%d %d %d",&Roadlist[i].A,&Roadlist[i].B,&Roadlist[i].L);
  }
     
  //ソート
  sort(Roadlist,Roadlist+M);
     
  //初期化
  for(i=2;i<N+1;i++){
    Farmlist[i] = false;
  }
  Farmlist[0] = true;//ダミー
  Farmlist[1] = true;//プリム法の処理 : 任意の頂点1つを集合に入れる
     
  for(j=0;j<N-1;j++){
     
    //プリム法
    for(i=0;i<M;i++){
      if(Farmlist[Roadlist[i].A] && !Farmlist[Roadlist[i].B]){ 	//道の両端のどちらか一方のみが集合に含まれるならその道を追加する
     
    	Farmlist[Roadlist[i].B] = true;
    	ans = max(ans,Roadlist[i].L);
    	break;
     
      }else if(!Farmlist[Roadlist[i].A] && Farmlist[Roadlist[i].B]){
     
    	Farmlist[Roadlist[i].A] = true;	
    	ans = max(ans,Roadlist[i].L);
    	break;
      }
    }
  }
     
  printf("%d\n",ans);
     
  free(Farmlist);
  free(Roadlist);
     
  return 0;
}

