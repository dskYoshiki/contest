#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
     
using namespace std;
     
const int MAX_N = 300;
const int INF = 1000000;
     
int cost[MAX_N][MAX_N];
int N, M;
int group;
int mem[MAX_N];
     
void init_cost(){//cost[][]を初期化
  for(int u = 0; u < N; u++){
    for(int v = 0; v < N; v++){
      cost[u][v] = INF;
    }
  }
}
     
void warshall_floyd(){
  for(int k = 0; k < N; k++ ){
    for(int i = 0; i < N; i++ ){
      for(int j = 0; j < N; j++ ){
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
}
     
     
int solve(){
  int ans = INF;
     
  warshall_floyd();
     
  for(int u = 0; u < N; u++){//頂点uから頂点vまでのcostを足す
    int temp = 0;
    for(int v = 0; v < N; v++){
      temp += cost[u][v];
    }
    ans = min(ans, temp);
  }
  return ans;
}
     
int main(){
  cin >> N >> M;
     
  init_cost(); //初期化
     
  for(int i = 0; i < M; i++){
    cin >> group;
    for(int j = 0; j < group; j++){
      cin >> mem[j];
      mem[j] = mem[j] - 1; //頂点は0~(n-1)
    }
    for(int u = 0; u < group; u++){
      for(int v = 0; v < group; v++){
        if(mem[v] == mem[u]){
          cost[mem[u]][mem[v]] = 0;
        }
        else{
          cost[mem[u]][mem[v]] = 1;
        }
      }
    }
  }
     
  cout << (solve() * 100) / (N - 1) << endl;
     
  return 0;
}

