#include <iostream>
#include <vector>
#include <algorithm>
     
#define INF 100000
     
using namespace std;
     
int solve2(int n, int r, vector<int> route, vector< vector<int> > &l, vector< vector<int> > &s){
     
  //DPテーブルdp[i][j]
  //0番目からi番目の集配を行い、i番目への集配が終わったときに船がjにある時の0からi番目までの最短距離
  vector< vector<int> > dp;
  dp.resize(r);
  for(int i = 0; i < r; i++) dp[i].resize(n);
     
  for(int i = 0; i < r; i++){
    for(int j = 0; j < n; j++){
      if( i == 0  && j == route[0]) dp[i][j] = 0;
      else dp[i][j] = INF;
    }
  }
     
  for(int i = 1; i < r; i++){
    for(int j = 0; j < n; j++){//i番目までの集配を終えたときの船の位置
      for(int k = 0; k < n; k++){//k : i-1番目までの集配を終えたときの船の位置
        if(j != k)
          dp[i][j] = min( dp[i][j], dp[i-1][k] + l[route[i-1]][k] + s[k][j] +l[j][route[i]] );
        else
          dp[i][j] = min( dp[i][j], dp[i-1][j] + l[route[i-1]][route[i]] );
      }
    }
  }
     
  int ans = INF;
  for(int i = 0; i < n; i++){
    ans = min( ans, dp[r-1][i] );
  }
  return ans;
}
     
void solve1(int n, vector< vector<int> > &l, vector< vector<int> > &s){
     
  //陸路のみと海路のみの最短距離をそれぞれ求める
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
        s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
      }
    }
  }
     
}
     
int main(){
     
  while(1){
     
    int n, m;
    cin >> n >> m;
     
    if(n == 0 && m == 0) return 0;
     
    vector< vector<int> > l, s;
    l.resize(n);
    for(int i = 0; i < n; i++) l[i].resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++) s[i].resize(n);
     
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i == j){
          l[i][j] = 0;
          s[i][j] = 0;
        }
        else{
          l[i][j] = INF;
          s[i][j] = INF;
        }
      }
    }
     
    int x, y, t;
    char sl;
     
    for(int i = 0; i < m; i++){
      cin >> x >> y >> t >> sl;
      if(sl == 'L'){
        l[x-1][y-1] = t;
        l[y-1][x-1] = t;
      }
      else{
        s[x-1][y-1] = t;
        s[y-1][x-1] = t;
      }
    }
     
    solve1(n, l, s); //陸路のみと海路のみの最短距離をそれぞれ求める
     
    int r;
    cin >> r;
     
    vector<int> route;
    for(int i = 0; i < r; i++){
      int area;
      cin >> area;
      route.push_back(area-1);
    } 
     
    cout << solve2(n, r, route, l, s) << endl; //陸路と海路含めた最短距離を求める
     
  }
     
  return 0;
}

