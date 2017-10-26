#include <cstdio>
#include <vector>
using namespace std;
     
const int M = 1e9 + 7;
vector<long long> dp;
     
long long dfs(int parent, int n, vector<vector<int> > &adj)
{
  if (dp[n])
    return dp[n];
     
  long long black = 1, white = 1;
     
  for (int v: adj[n]) {
    if (v != parent) {
      white = (white * dfs(n, v, adj)) % M;
      for (int u: adj[v]) {
        if (u != n) {
          black = (black * dfs(v, u, adj)) % M;
        }
      }
    }
  }
  return dp[n] = (white + black) % M;
}
     
int main()
{
  int N;
  scanf("%d", &N);
  dp.resize(N);
  fill(dp.begin(), dp.end(), 0);
     
  vector<vector<int> > adj(N);
  for (int i = 0; i < N-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
     
  printf("%lld\n", dfs(0, 0, adj) );
     
  return 0;
}

