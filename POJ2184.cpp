#include<iostream>
#include<algorithm>
 
using namespace std;
 
const int MIN = - (100 * 2000 + 1);
int dp[2][100 * 2000 + 1];
 
int solve(int n, int *smartness, int *funness)
{
  std::fill( dp[0], dp[2], MIN );
 
  int *prv = dp[0], *nxt = dp[1];
 
  prv[100000] = 0;
 
  int upperBound = 1;
  int lowerBound = 0;
  int upperBoundNext = 1;
  int lowerBoundNext = 0;
 
  for(int i = 0; i < n; i++){
    for(int j = lowerBound; j < upperBound; j++){
      if(nxt[100000 + j] < prv[100000 + j])
        nxt[100000 + j] = prv[100000 + j];
 
      if(prv[100000 + j] != MIN 
         && nxt[100000 + j + smartness[i]] < prv[100000 + j] + funness[i]){
 
        nxt[100000 + j + smartness[i]] = prv[100000 + j] + funness[i];
 
        if(j + smartness[i] > upperBoundNext)
          upperBoundNext = j + smartness[i] + 1;
        else if(j + smartness[i] < lowerBoundNext)
          lowerBoundNext = j + smartness[i];
 
      }
 
    }
 
    upperBound = upperBoundNext;
    lowerBound = lowerBoundNext;
 
    swap(prv, nxt);
 
  }
 
  int res = 0;
 
  for(int i = lowerBound; i < upperBound; i++){
    if(i >= 0 && prv[100000 + i] >= 0)
      res = max(res, i + prv[100000 + i]);
  }
 
  return res;
 
}
 
 
 
 
int main()
{
  int n;
 
  int *smartness, *funness;
 
  cin >> n ;
 
 
  smartness = new int[n];
  funness = new int[n];
 
  for(int i = 0; i < n; i++)
    cin >> smartness[i] >> funness[i];
 
 
  cout << solve(n,smartness, funness) << endl;
 
  delete(smartness);
  delete(funness);
 
  return 0;
}
