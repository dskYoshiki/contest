#include <cstdio>
#include <iostream>
#include <cmath>
     
using namespace std;
     
const int MAX_N = 1000000;
     
int dp[MAX_N+1];
int power2[21] = {0};
     
/* 2のj乗を計算する */
int getPower2(int j){
  if(power2[j] > 0) return power2[j];
  else{
    power2[j] = 2 * getPower2(j-1);
    return power2[j];
  }
}
     
void solve(int n) {
  /* 初期化 */
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
  }
     
  /* 使う値の最大値が小さいものから求めていく */
  for (int j = 1; j <= log2(n); j++) {
    for (int i = getPower2(j); i <= n; i++) {
      if (i == getPower2(j)) {
        dp[i] += 1;
      } else {
        int k = i - getPower2(j);
        dp[i] += dp[k];
      }
      dp[i] = dp[i] % 1000000000;
    }
  }
     
  printf("%d\n", dp[n]);
}
     
int main() {
  int n;
  cin >> n;
     
  power2[0] = 1;
  solve(n);
     
  return 0;
}

