//Warning
#include <cstdio>
#include <iostream>
#include <queue>
     
using namespace std;
     
class Edge {
public:
  Edge() {}
  Edge(int to, int cost): to(to), cost(cost) {}
  inline int getTo() { return to; }
  inline int getCost() { return cost; }
     
private:
  int to;
  int cost;
};
     
const int MAX_N = 1000;
const int INF = 10000000;
     
int N, M, X;
     
typedef pair<int, int> P; // first:最短距離, second:頂点番号
vector<Edge> E[MAX_N]; // 隣接リスト
int d[MAX_N];
int t[MAX_N]; // 往復にかかる時間
     
/* 始点Sから各頂点への最短路 */
void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+N, INF); // dをINFで初期化
  d[s] = 0;
  que.push(P(0, s));
     
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < E[v].size(); i++) {
      Edge e = E[v][i];
      if (d[e.getTo()] > d[v] + e.getCost()) {
        d[e.getTo()] = d[v] + e.getCost();
        que.push(P(d[e.getTo()], e.getTo()));
      }
    }
  }
}
     
int solve() {
  /* 復路の計算 */
  dijkstra(X-1);
  for (int i = 0; i < N; i++) t[i] = d[i];
     
  /* 往路の計算 */
  for (int i = 0; i < X-1; i++) {
    dijkstra(i);
    t[i] += d[X-1];
  }
  for (int i = X; i < N; i++) {
    dijkstra(i);
    t[i] += d[X-1];
  }
     
  /* 往復の時間が最もかかる牛を探す */
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (ans < t[i]) ans = t[i];
  }
     
  printf("%d\n", ans);
}
     
int main()
{
  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    int v1, v2, cost;
    scanf("%d %d %d", &v1, &v2, &cost);
    v1--; v2--;
    E[v1].push_back(Edge(v2, cost));
  }
     
  solve();
  return 0;
}

