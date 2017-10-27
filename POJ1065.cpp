#include <cstdio>
#include <iostream>
#include <algorithm>
     
using namespace::std;
const int MAX_N = 5000;
struct stick{int l, w;
  bool done;}x[MAX_N];
     
bool comp(const stick& x1 , const stick& x2){
  return (x1.l < x2.l || (x1.l==x2.l && x1.w < x2.w));
}
     
int solve(int n){
  int ans=0, i=0;
  int count = 0;
  sort(x, x+n, comp);
     
  while(count<n){ 
    ans++;
    for(int j=i; j<n; j++){
      if(!x[j].done){ i=j; break;}
    }
    x[i].done=true;
    count++;
    int tmpl = x[i].l;
    int tmpw = x[i].w;
    if(i<n-1){
      for(int j=i+1; j<n; j++){
        if(x[j].l >= tmpl && x[j].w >= tmpw && !x[j].done){
          x[j].done=true;
          count++;
          tmpl = x[j].l;
          tmpw = x[j].w;
        }
      }
    }
  }
  return ans;
}
     
int main() {
  int m;
  int n;
     
  cin >> m;
  for(int j=0; j<m; j++){
    cin >> n;
    for(int i = 0; i<n; i++) {
      cin >> x[i].l >> x[i].w;
      x[i].done = false;
    }
    cout << solve(n) << endl;
  }
}

