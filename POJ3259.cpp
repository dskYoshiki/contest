#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
     
#define INFTY 5000000
     
using namespace std;
     
class Arrow{
public:
  Arrow(){}
  Arrow(int from, int to, int time): from(from), to(to), time(time) {}
     
  int from;
  int to;
  int time;
};
     
int dist[500];
//const int INFTY = 5000000; //こっちだと235ms
     
void relax(Arrow &a)
{
  if(dist[a.from] != INFTY)
    dist[a.to] = min(dist[a.to], dist[a.from] + a.time);
}
     
     
     
string solve(int n,vector<Arrow> &arrowSet)
{
  fill( dist + 1, dist + n, INFTY);
  dist[0] = 0;
     
  for(int i = 0; i < n - 1; i++){
    for_each(arrowSet.begin(), arrowSet.end(), relax);
  }
     
  for(vector<Arrow>::iterator arrow = arrowSet.begin(); arrow != arrowSet.end(); arrow++){
    if(dist[(*arrow).to] > dist[(*arrow).from] + (*arrow).time)
      return "YES";
  }
     
  return "NO";  
}
     
     
     
int main()
{
  int f, n, m, w, s, e, t;
  vector<Arrow> arrowSet;
     
  scanf("%d", &f);
     
  for(int i = 0; i < f; i++){
    scanf("%d %d %d", &n, &m, &w);
     
    arrowSet.clear();
     
    for(int j = 0; j < m; j++){
      scanf("%d %d %d", &s, &e, &t);
     
      arrowSet.push_back(Arrow(s-1,e-1,t));
      arrowSet.push_back(Arrow(e-1,s-1,t));
    }
     
    for(int j = 0; j < w; j++){
      scanf("%d %d %d", &s, &e, &t);
     
      arrowSet.push_back(Arrow(s-1,e-1,-1 * t));
    }
    cout << solve(n, arrowSet) << endl;
  }
     
}

