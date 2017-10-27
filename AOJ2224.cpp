#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
     
class Edge
{
public:
  int p, q;
  double cost;
     
  Edge(){}
  Edge(int p, int q, double cost) : p(p), q(q), cost(cost) {}
  bool operator<(const Edge& e) const {
    return cost > e.cost;
  }
};
     
class UnionFind
{
  vector<int> parent;
public:
  UnionFind(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
     
  int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
  }
     
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[x] = y;
  }
     
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};
     
double kruskal(int n, int m, vector<Edge>& E)
{
  UnionFind T(n);
  sort(E.begin(), E.end());
  double result = 0;
     
  for (int i = 0; i < m; i++) {
    if (!T.same(E[i].p, E[i].q)) {
      T.unite(E[i].p, E[i].q);
      result += E[i].cost;
    }
  }
  return result;
}
     
inline double length(int x1, int x2, int y1, int y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
     
int main()
{
  int N, M;
  scanf("%d %d", &N, &M);
     
  vector<int> X, Y;
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    X.push_back(x);
    Y.push_back(y);
  }
     
  vector<Edge> E;
  double total_cost = 0;
  for (int i = 0; i < M; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    p--; q--;
    double cost = length(X[p],X[q],Y[p],Y[q]);
    total_cost += cost;
    E.push_back( Edge(p, q, cost) );
  }
     
  printf("%.4f\n", total_cost - kruskal(N,M,E));
  return 0;
}

