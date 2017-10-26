#include <cstdio>
#include <iostream>

using namespace std;
const int MAX_N = 3500;
int main(){
  int N;
  cin >> N;
  // int A[N];
  // int B[N];
  // int maxA=0;int max=0;
  // for(int i=0; i<N; i++){
  //   cin >> A[i] >> B[i];
  //   if(A[i]>maxA){
  //     max = A[i] + B[i];
  //     maxA =A[i];
  //   }
  // }
  // cout << max << endl;

  // int dp[MAX_N];
  // for(int i=0; i<MAX_N; i++){
  //   dp[i]=0;
  // }
  int ans[3];
  for(int i=1; i<=MAX_N; i++){
    for(int j=1; j<=MAX_N; j++){
      for(int k=0; k<=MAX_N; k+=N){
        if((4*i*j*k) == N*(i*j + j*k + k*i)){
          ans[0]=i;
          ans[1]=j;
          ans[2]=k;
          break;
        }
      }
    }
  }
  cout << ans[0]<< " " << ans[1] << " " << ans[2] << endl;
  return 0;
}
