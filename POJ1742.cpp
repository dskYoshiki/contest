//Warning
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
     
using namespace std;
     
const int MAX_N = 100000;
const int MAX_M = 100000;
     
int solve(int n, int m, int *a, int *c, int *dp){
  int ans=0;
  // printf("n=%d, m=%d, A[2]=%d, C=[2]%d\n", n, m, A[2], C[2]);
  memset(dp,-1,sizeof(dp));
  dp[0]=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<=m; j++){
      if(dp[j]>=0) dp[j] = c[i];
      else if(j<a[i] || dp[j-a[i]]<=0) dp[j] = -1;
      else dp[j] = dp[j-a[i]]-1;
    }
  }
  for (int j = 1; j <= m; j++) {
    if (dp[j] >= 0) ans++;
  }
  return ans;
}
     
int main()
{
  int n, m;
  int dp[MAX_M + 1];
  int a[MAX_N], c[MAX_N];
  while (1) {
    cin >> n >> m;
    int *dp = new int [m+1];
    int *a = new int [n];
    int *c = new int [n];
    if((n == 0) && (m == 0)) break;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    cout << solve(n, m, a, c, dp) << endl;
  }
  return 0;
}

