#include <cstdio>
#include <queue>
#include <iostream>
     
using namespace std;
     
const int MAX_N = 100000;
     
int N, M;
int X[MAX_N], Y[MAX_N];
char Rel[MAX_N];
int par[MAX_N*2];
     
void init() {
  for (int i = 0; i < N*2; i++) {
    par[i] = i;
  }
}
     
int find(int x) {
  if (par[x] == x) return x;
     
  else return par[x] = find(par[x]);
}
     
void unite(int x, int y) {
  par[find(x)] = find(y);
}
     
bool same(int x, int y) {
  return find(x) == find(y);
}
     
void solve() {
  init();     
  for (int i = 0; i < M; i++) {
    char rel = Rel[i];
    int x = X[i], y = Y[i];
    if (rel == 'A') { 
      if (same(x, y)) cout << "In the same gang." << endl;
     
      else if(same(x+N, y)) cout << "In different gangs." << endl;
     
      else cout << "Not sure yet." << endl;
    }
    else if(rel == 'D'){
      unite(x, y+N);
      unite(x+N, y);
    }
  }
}
     
     
int main()
{
  int T;
  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> N >> M;
    for(int j = 0; j < M; j++){
      cin >> Rel[j] >> X[j] >> Y[j];
    }
    solve();
  }    
  return 0;
}

