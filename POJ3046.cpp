#include <iostream>
#include <vector>
     
using namespace::std;
     
int solve(int t, int a, int s, int b, vector<int> t_count){
     
  vector< vector<int> > dp;
  dp.resize(t);
  for(int i = 0; i < t; i++){
    dp[i].resize(a+1);
    fill(dp[i].begin(), dp[i].end(), 0);
  }
     
  fill(dp[0].begin(), dp[0].begin()+t_count[0]+1, 1);
  for(int i = 1; i < t; i++){//１つも選ばない時はいつも1通り
    dp[i][0] = 1;
  }
     
  for(int i = 1; i < t; i++){
    for(int j = 1; j <= a; j++){
      if(j - 1 - t_count[i] >= 0){
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j - 1 - t_count[i]];
      }
      else{
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }
     
  int ans = 0;
  for(int i = s; i <= b; i++){
    ans += dp[t-1][i];
  }
     
  return ans;
}
     
int main(){
     
  int t, a, s, b;
  cin >> t >> a >> s >> b;
     
  vector<int> n;
  for(int i = 0; i < a; i++){
    int s;
    cin >> s;
    n.push_back(s-1);
  }
     
  vector<int> t_count;
  for(int i = 0; i < t; i++) t_count.push_back(0);
     
  for(int i = 0; i < t; i++){
    for(int j = 0; j < a; j++) if(n[j] == i) t_count[i]++;
  }
     
  cout << solve(t, a, s, b, t_count) << endl;
     
  return 0;
}

