#include <cstdio>
#include <vector>
#include <queue>
     
using namespace std;
     
typedef pair<int, int> P;
#define MAX_N 105
     
int N;//農場の数
int cost[MAX_N][MAX_N];//入力に使う2次配列
     
int prim() {
  vector<bool> used(N+1);//その農場を経由したかどうかの判定。
  fill(used.begin(),used.end(),false);//falseで初期化
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0,0));
     
  int ans = 0;//ansの初期化
  while (!que.empty()) {//queが空でないなら続ける
    P p = que.top();
    que.pop();
    int v = p.second;
    if (!used[v]) {
      used[v] = true;
      ans += p.first;
      for (int u=0; u<N; ++u) {
    	if (!used[u])
    	  que.push(P(cost[v][u],u));
      }
    }
  }
     
  return ans;
}
     
int main(){
  while(scanf("%d",&N) != EOF)
    {
      for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
          int c;
          scanf("%d",&c);
          cost[i][j] = c;
        }
      }
      printf("%d\n",prim());
    }
     
}

