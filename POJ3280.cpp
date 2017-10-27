#include <iostream>
#include <algorithm>
     
using namespace::std;
     
struct id{
  char s;
  int in, out;
};
     
struct kind{
  char s;
  int in, out;
};
     
int solve( int n, int m, id* c ){
     
  int** dp = new int*[m];
  for(int i = 0; i < m; i++) dp[i] = new int[m];//テーブルの動的確保
     
  for(int i = 0; i < m; i++){//dpの初期化
    for(int j = 0; j < m; j++){
      dp[i][j] = 0;
    }
  }
     
  for(int j = 0; j < m; j++){//動的計画法
    for(int i = j; i >= 0; i--){
      if( i == j ) dp[i][j] = 0;
      else if( c[i].s == c[j].s && i < m-1 && j > 0 ) dp[i][j] = dp[i+1][j-1];
      else if( i < m-1 && j > 0 ){
        dp[i][j] = min(
                       dp[i][j-1] + min(c[j].in, c[j].out),
                       dp[i+1][j] + min(c[i].in, c[i].out)
                       );
      }
      else if( i < m-1 && j == 0 ) dp[i][j] = dp[i+1][j] + min(c[i].in, c[i].out);
      else if( i == m-1 && j > 0 ) dp[i][j] = dp[i][j-1] + min(c[j].in, c[j].out);
    }
  }
     
  int ans = dp[0][m-1];
     
  for(int i = 0; i < m; i++) {
    delete[] dp[i];
  }
  delete[] dp;
     
  return ans;
}
     
int main()
{
  int n, m;
  cin >> n >> m;
     
  id* c = new id[n];
  for(int i = 0; i < m; i++) cin >> c[i].s;
     
  kind* k = new kind[n];
  for(int i = 0; i < n; i++) cin >> k[i].s >> k[i].in >> k[i].out;
     
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if( c[i].s == k[j].s ){
        c[i].in  = k[j].in;
        c[i].out  = k[j].out;
      }
    }
  }
     
  cout << solve(n, m, c) << endl;
     
  return 0;
}

