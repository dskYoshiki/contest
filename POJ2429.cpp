#include <iostream>
#include <cmath>
#include <cstdio>
     
typedef unsigned long long int ll; 
using namespace std;
     
const ll INF = 0xffffffffffffffff;
     
     
ll gcd(ll a, ll b){
     
  if(b == 0)  return a;
     
  return gcd(b, a % b);
}
     
int main(){
  ll a, b, c;
  while(cin >> a >> b){
     
    ll x = INF;
    ll y = INF;
    ll tempX = 0;
    ll tempY = 0;
     
    c = b/a;
    long double temp = c;
     
    for(int i = sqrt(temp); i >= 1; i--){
      if((c%i == 0) && (gcd(i, c/i) == 1)){
        tempX = a*i;
        tempY = b/i;
        if((x + y) > (tempX + tempY)){
          x = tempX;
          y = tempY;
        }
      }
    }
     
    printf("%lld %lld\n", x, y);
  }
     
  return 0;
}

