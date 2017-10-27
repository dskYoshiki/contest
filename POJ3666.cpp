#include <vector>
#include <iostream>
#include <algorithm>
     
using namespace::std;
     
//dp[i][j] := 0~i番目のポイントに対して、iの高度をjとしたときの最小コスト
//iの高度を変更したとき、その高度はaのある要素の高度と等しい
//そのため、dpテーブルの列数はn列あれば十分
     
int dp[2000][2000];
     
int solve( int n, vector<int> a, vector<int> b){
     
  for(int i = 0; i < n; i++){
    dp[0][i] = abs(a[0] - b[i]);
  }
     
  for(int i = 1; i < n; i++){
    int temp = dp[i-1][0];
    for(int j = 0; j < n; j++){
      temp = min(dp[i-1][j], temp);
      dp[i][j] = temp + abs(a[i] - b[j]);
    }
  }
     
  int ans = *min_element(dp[n-1], dp[n-1]+n);
     
  return ans;
}
     
int main(){
     
  int n;
  cin >> n;
     
  vector<int> a;
  for(int i = 0; i < n; i++){
    int s;
    cin >> s;
    a.push_back(s);
  }
     
  vector<int> b = a;
  sort(b.begin(), b.end());
  int ans = solve(n, a, b);
     
  reverse(b.begin(), b.end());
  cout << min( ans , solve(n, a, b) ) << endl;
     
  return 0;
}

