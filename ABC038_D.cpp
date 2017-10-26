#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
     
using namespace std; 
     
const int MAX_N = 100000;
const int INF = 100001;
     
int main(){
     
  int N;
  int dp[MAX_N];
     
  cin >> N;
  vector<pair<int,int> > box(N);
     
  for(int i = 0; i < N; i++){
    cin >> box[i].first >> box[i].second;
    box[i].second *= -1;
  }
     
  sort(box.begin(), box.end());
     
  for(int i = 0; i < N; i++){
    box[i].second *= -1;
  }
     
  fill(dp, dp + N, INF);
     
  for(int i = 0; i < N; i++){
    *lower_bound(dp, dp + N, box[i].second) = box[i].second;
  }
  cout << lower_bound(dp, dp + N, INF) - dp << endl;
     
  return 0;
}

