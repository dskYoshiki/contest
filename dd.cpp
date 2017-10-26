#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  int B[N];
  int maxA=0;int max=0;
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
    if(A[i]>maxA){
      max = A[i] + B[i];
      maxA =A[i];
    }
  }
  cout << max << endl;
  return 0;
}
