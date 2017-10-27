#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
     
using namespace std;
     
const int MAX_C = 100000;
     
int n, c, f;
     
void solve(vector<pair<int, int> > cow) {
  /* i番目の牛のscoreを中央値とした時のaidの合計の最小値 */
  int aidsum[MAX_C];
  priority_queue<int> que1;
  priority_queue<int> que2;
     
  int aid = 0;
  const int start = n/2;
  const int end = c - n/2 - 1;
  int median = -1;
     
  sort(cow.begin(), cow.end()); // scoreを昇順にソート
     
  /* キューの初期状態の設定 */
  que1.push(0);
  for (int i = 0; i < start; i++) {
    aid += cow[i].second;
    que1.push(cow[i].second);
  }
     
  aidsum[start] = aid + cow[start].second;
     
  for (int i = start+1; i <= end; i++) {
    if (que1.top() > cow[i-1].second) {
      int q = que1.top();
      que1.pop();
      que1.push(cow[i-1].second);
      aid = aid - q + cow[i-1].second;
    }
    aidsum[i] = aid + cow[i].second;
  }
     
  reverse(cow.begin(), cow.end()); // scoreを降順にソート
     
  aid = 0;
  que2.push(0);
  /* キューの初期状態の設定 */
  for (int i = 0; i < start; i++) {
    aid += cow[i].second;
    que1.push(cow[i].second);
  }
     
  aidsum[end] += aid;
  for (int i = start+1; i <= end; i++) {
    if (que1.top() > cow[i-1].second) {
      int q = que1.top();
      que1.pop();
      que1.push(cow[i-1].second);
      aid = aid - q + cow[i-1].second;
    }
    aidsum[c-i-1] += aid;
  }
  reverse(cow.begin(), cow.end()); // scoreを昇順にソート
     
  /* aidsum[i]の中からfを超えない最大値を探す */
  for (int i = start; i <= end; i++) {
    if (aidsum[i] <= f && median < cow[i].first) {
      median = cow[i].first;
    }
  }
     
  if (median == -1) {
    printf("-1\n");
  } else {
    printf("%d\n", median);
  }
}
     
int main()
{
  vector<pair<int, int> > cow;
     
  scanf("%d %d %d", &n, &c, &f);
     
  int score, aid;
  for (int i = 0; i < c; i++) {
    scanf("%d %d", &score, &aid);
    cow.push_back( make_pair(score, aid) );
  }
     
  solve(cow);
     
  return 0;
}

