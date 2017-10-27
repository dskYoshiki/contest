#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
     
using namespace std;
     
double solve(int n, priority_queue<double>& s){
  while ( s.size() > 1 ) {
    double s1 = s.top();
    s.pop();
    double s2 = s.top();
    s.pop();
    s.push( 2 * sqrt( s1*s2 ) );
  }
     
  return s.top();
}
     
int main(){
  int n;
  scanf("%d", &n);
  priority_queue<double> stripies;
  for (int i = 0; i < n; i++) {
    double stripy;
    scanf(" %lf ", &stripy);
    stripies.push(stripy);
  }
     
  printf("%.3lf\n", solve(n, stripies));
}

