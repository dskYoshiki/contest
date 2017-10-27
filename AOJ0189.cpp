#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <iostream>
     
using namespace std;
     
struct edge{int to, cost;};
typedef pair<int, int> P;
const int INF = 0x7ffffff;
     
int town;
vector<edge> G[10];
int d[10];
int ans[2];
     
void dijkdstra(int s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+town, INF);
  d[s]=0;
  que.push(P(0,s));
     
  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
    int size = G[v].size();
    for(int i=0; i<size; i++){
      edge e = G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
     
void solve(){
  int tmp;
  dijkdstra(0);
  ans[0] = 0;
  //for(int i=0; i<town; i++)  printf("%d ", d[i]);
  for(int i=0; i<town; i++) ans[1] +=d[i];
     
  for(int i=1; i<town; i++){
    tmp = 0;
    dijkdstra(i);
    for(int j=0; j<town; j++) tmp +=d[j];
    if(ans[1]>tmp){
      ans[0] = i;
      ans[1] = tmp;
    }
  }
}
     
int main() {
  int r;
  cin >> r;
  while(r!=0){
    int from, to, cost;
    edge ed;
    town = 0;
    for (int i = 0; i < r; i++) {
      cin >> from >> to >> cost;
      town = max(town,max(from+1,to+1));
      ed.to = to;
      ed.cost = cost;
      G[from].push_back(ed);
      ed.to = from;
      G[to].push_back(ed);
    }
    solve();
    printf("%d %d\n", ans[0], ans[1]);
     
    for (int i = 0; i < town; i++) G[i].erase(G[i].begin(), G[i].end());
    cin >> r;
  }
  return 0;
}

