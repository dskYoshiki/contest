#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
     
using namespace std;
     
typedef unsigned long long ll;
const ll INF = 0xffffffff;
ll p, q;
     
ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a%b);
}
     
void solve(string recur){
  int d = recur.length();       // 小数部分の桁数
  int x = atoi(recur.c_str());  // 小数部分の整数表示
  ll denominator;               // 分母
  ll numerator;                 // 分子
  q = INF;
     
  for (int i = 1; i <= d; i++) {
    numerator = x - x/(int)pow(10.0, i);
    denominator = pow(10.0, d) - pow(10.0, d-i);
    ll g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    if ( denominator < q ) {
      q = denominator;
      p = numerator;
    }
  }
}
     
int main(){
  string s;
  cin >> s;
     
  do {
    s = s.substr(2, s.size()-5);
    solve(s);
    cout << p << "/" << q << endl;
    cin >> s;
  } while ( s != "0" );
}

