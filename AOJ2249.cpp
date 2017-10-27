//Warning
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
     
using namespace std;
     
class Edge{
public:
  Edge(){}
  Edge(int to, int d, int cost): to(to), d(d), cost(cost) {}
  bool operator<(const Edge& e) const {
    if ( d != e.d )
      return d > e.d;
    else
      return cost > e.cost;
  }
     
  int to;
  int d;
  int cost;
};
     
int N = -1;
int M = -1;
vector<Edge> E[10000];
bool done[10000];
     
int solve(){
  memset(done, 0, sizeof(done));
  priority_queue<Edge> q;
  q.push(Edge(0,0,0));
  int ans = 0;
     
  while ( q.size() ) {
    int v = q.top().to;
    int d = q.top().d;
    int cost = q.top().cost;
    q.pop();
     
    if ( done[v] ) continue;
     
    done[v] = true;
    ans += cost;
    for (int i = 0; i < E[v].size(); i++) {
      q.push(Edge(E[v][i].to, E[v][i].d + d, E[v][i].cost));
    }
  }
     
  return ans;
}
     
int main(){
  while ( N != 0 ) {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
      E[i].clear();
    }
    for (int i = 0; i < M; i++) {
      int u, v, d, c;
      scanf(" %d %d %d %d", &u, &v, &d, &c);
      u--; v--;
      E[u].push_back(Edge(v, d, c));
      E[v].push_back(Edge(u, d, c));
    }
    if ( N != 0 )
      printf("%d\n", solve());
  }
}

