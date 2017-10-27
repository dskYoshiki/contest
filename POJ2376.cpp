#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
     
using namespace std;
     
const int MAX_N = 25000;
     
int main()
{
  int n, t;
  pair<int, int> cow[MAX_N];
     
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &cow[i].first, &cow[i].second);
  }
     
  sort(cow, cow + n); // 開始時刻でソート
     
  int cur = 0, nxt;
  int num = 0;
  int ans = 0;
     
  while (cur < t) {
    while (num < n && cow[num].first <= cur+1) {
      nxt = max(nxt, cow[num].second);
      num++;
    }
    if (cur == nxt) break;
    cur = nxt;
    ans++;
  }
     
  if (nxt < t) printf("-1\n");
  else printf("%d\n", ans);
  return 0;
}

