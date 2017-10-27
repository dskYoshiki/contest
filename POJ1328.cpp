#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
     
int solve(int d, vector<pair<int,int> >& P)
{
  sort(P.begin(), P.end());
     
  int answer = 1;
  vector<pair<int,int> >::const_iterator p = P.begin();
  double x = (*p).first;
  double y = (*p).second;
     
  while (p != P.end()) {
    if (x + sqrt(d*d - y*y) >= ((*p).first - sqrt(d*d - (*p).second * (*p).second))) {
      if (x + sqrt(d*d - y*y) > ((*p).first + sqrt(d*d - (*p).second * (*p).second))) {
        x = (*p).first;
        y = (*p).second;
      }
    }
    else {
      answer++;
      x = (*p).first;
      y = (*p).second;
    }
    ++p;
  }
     
  return answer;
}
     
int main()
{
  int n, d;
  int count = 0;
  int answer = 0;
     
  cin >> n >> d;
  while (n || d) {
    count++;
     
    vector<pair<int,int> > P;
    int x,y;
    for (int i=0; i<n; i++) {
      cin >> x >> y;
      P.push_back(make_pair(x,y));
     
      if (y > d) {
        answer = -1;
      }
    }
     
    if (answer != -1) {
      answer = solve(d, P);
    }
     
    cout << "Case " << count << ": " << answer << endl;
     
    answer = 0;
    cin >> n >> d;
  }
     
  return 0;
}

