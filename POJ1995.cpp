#include <cmath>
#include <iostream>
     
using namespace::std;
     
long long mod_pow(long long a, long long b, int m){//aのb乗をmで割った余りを求める
     
  long long ans = 1;
  while(b > 0){
    if(b & 1) ans = ans * a % m;
    a = a * a % m;
    b = b >> 1;
  }
  return ans;
}
     
int main(){
     
  long long z;//データセット数
  cin >> z;
     
  for(long long i = 0; i < z; i++){
     
    int m, n;
    cin >> m >> n;
     
    long long ans = 0;
    for(int i = 0; i < n; i++){
      long long a, b;
      cin >> a >> b;
      ans = ( ans + mod_pow(a, b, m) ) % m;
     
    }
    cout << ans << endl;
  }
     
  return 0;
}

