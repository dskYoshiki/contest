#include <cstdio>
#include <iostream>
#include <vector>
#define INF 1000000000;
using namespace std;
     
     
     
bool is_prime(int n){
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0)
      return false;
  }
  return n != 1;
}
     
bool is_pseudoprime(long long p,long long a){
  long long res = 1;
  long long x = a;
     
  if(is_prime((int)p)) return false;
     
  for(int i = p;i > 0; i>>=1){
    if(i&1){
      res = (res * x) % p;
    }
    x = (x * x) % p;
  }
  return (res % p) ==a;
}
     
int main(){
  int p =INF;
  int a =INF;
  while(p != 0 && a != 0){
    scanf("%d %d",&p,&a);
    if(is_pseudoprime((long long)p,(long long)a)){
      printf("yes\n");
    }else{
      printf("no\n");
    }
  }
  return 0;
}

