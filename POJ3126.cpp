//Warning
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
     
using namespace std;
     
const int INF = 1000000;
     
vector<int> E[9000]; // 隣接リスト
int d[9000]; // 各点までの最短距離
     
bool is_prime[9000];
bool is_prime_small[100];
     
void prime() {
  for(int i = 0; i < 100; i++) is_prime_small[i] = true;
  for(int i = 0; i < 9000; i++) is_prime[i] = true;
  for(int i = 2; i < 100; i++) {
    if(is_prime_small[i]) {
      for(int j = 2*i; j < 100; j += i)
        is_prime_small[j] = false;
      for(int j = max(2, (1000+i-1) / i) * i; j < 10000; j += i)
        is_prime[j-1000] = false;
    }
  }
}
     
/* 頂点fromに隣接する辺のうち */
/* dnum桁目が異なる素数の頂点への辺を追加 */
void addEdge(int from, int p, int dnum) {
  int pp = p - 1;
  while (pp >= 0) {
    int num = from + (int)pow(10, dnum - 1) * (pp - p);
    if (is_prime[num]) E[from].push_back(num + 1000);
    pp--;
  }
  pp = p + 1;
  while (pp < 10) {
    int num = from + (int)pow(10, dnum - 1) * (pp - p);
    if (is_prime[num]) E[from].push_back(num + 1000);
    pp++;
  }
}
     
void makeAdjList() { // 隣接リストを作る
  for (int i = 0; i < 9000; i++) {
    if (is_prime[i]) {
      int p = (i + 1000) / 1000;
      addEdge(i, p, 4);
      int j = (i + 1000) % 1000;
      p = j / 100;
      addEdge(i, p, 3);
      j = j % 100;
      p = j / 10;
      addEdge(i, p, 2);
      p = j % 10;
      addEdge(i, p, 1);
    }
  }
}
     
int bfs(int a, int b) {
  queue<int> que; // 頂点番号を入れとくprime-1000
     
  for (int i = 0; i < 9000; i++) {
    d[i] = INF;
  }
     
  que.push(a - 1000);
  d[a - 1000] = 0;
     
  while (que.size()) {
    int num = que.front();
    que.pop();
    if (num == b - 1000) break;
     
    for (int i = 0; i < E[num].size(); i++) {
      int nxt = E[num][i] - 1000;
      if (d[nxt] == INF) {
        que.push(nxt);
        d[nxt] = d[num] + 1;
      }
    }
  }
     
  return d[b - 1000];
}
     
int getMinCost(int a, int b) {
  return bfs(a, b);
}
     
     
int main()
{
  int n, a, b;
  cin >> n;
     
  prime();
  makeAdjList();
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", getMinCost(a, b));
  }
  return 0;
}

