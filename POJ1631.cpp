#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
     
const int MAX_P = 40000;
     
int main()
{
  int n;
  scanf("%d", &n);
     
  for (int scenario = 0; scenario < n; scenario++) {
    int p;
    scanf("%d", &p);
     
    vector<int> P;
    P.resize(p);
    for (int i = 0; i < p; i++) {
      scanf("%d", &P[i]);
    }
     
    vector<int> dp;
    dp.resize(p);
    fill(dp.begin(), dp.end(), MAX_P);
     
    for (int i = 0; i < p; i++)
      *lower_bound(dp.begin(), dp.end(), P[i]) = P[i];
     
    int answer = lower_bound(dp.begin(), dp.end(), MAX_P) - dp.begin();
     
    printf("%d\n", answer);
  }
     
  return 0;
}

