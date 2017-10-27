//Warning
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
     
using namespace std;     
     
//nを素因数分解するO(n^(1/2))
vector<int> prime_factor(int n){
  vector<int> res;
  for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
      res.push_back(i);
      n /= i;
    }
  }
  if(n != 1){
    res.push_back(n);
  }
     
  return res;
}
     
int main(){
     
  int n;
  vector<int> pfactor;
  vector<int>::const_iterator itr;
     
  while(scanf("%d",&n)!=EOF){
    int k = 0;
    pfactor = prime_factor(n);
     
    printf("%d ",pfactor.size());
     
    do{
      k++;    
    }while( next_permutation(pfactor.begin(), pfactor.end() ));
    printf("%d\n",k);
  }
}

