#include<cstdio>
#include<iostream>
     
using namespace std;
     
int main() {
  const int MAX_N = 100000;
  int N;
  int a[MAX_N + 1] = { 0 };
     
  long long int ans = 0, num = 0;
     
  cin >> N;
     
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
     
  for (int j = 0; j < N; j++) {
    num++;
    if (a[j] >= a[j + 1]) {
      ans += num * (num + 1) / 2;
      num = 0;
    }
     
  }
  cout << ans << endl;
  return 0;
}

