#include <cstdio>
#include <iostream>
#include <algorithm>
     
using namespace::std;
const int MAX_N = 350;
     
int main() {
  int n;
  int x[MAX_N][MAX_N];
     
  cin >> n;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<=i; j++) {
      cin >> x[i][j];
    }
  }
     
  for (int i=n-2; i>=0; i--) {
    for(int j=0; j<=i; j++){
      x[i][j] += max( x[i+1][j],x[i+1][j+1] );
    }
  }
  cout << x[0][0] << endl;
}

