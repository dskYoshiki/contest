#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M;
int meteor[310][310];
int dist[310][310];
// int dx[5] = {0, 0, 0, -1, 1};
// int dy[5] = {0, 1, -1, 0, 0};
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
const int MAX = 302;
const int INF = 1<<30;

//座標(x, y)がBoardの範囲内ならばtrue
inline bool inBoard(int x, int y){
  return (0 <= x && x <= MAX && 0 <= y && y <= MAX);
}

int solve(){
  //時刻0に(0, 0)に隕石が落下するとき
  if(meteor[0][0] == 0) return -1;

  //毎秒移動しなくてもよい場合
  if (meteor[0][0] == INF) return 0;
  
  int time = 0;
  int cx = 0, cy = 0;
  queue<pair<int,int> > que;
  
  que.push(make_pair(0, 0));
  dist[0][0] = 0;
  
  while (!que.empty()){
    pair<int,int> cur = que.front();
    que.pop();
    cx = cur.first;
    cy = cur.second;

    if (meteor[cx][cy] == INF) {
      return dist[cx][cy];
    }
    time = dist[cx][cy] + 1;
    if (dist[cx][cy] < meteor[cx][cy]){
      for (int j=1;j<5;j++){
          int nx = cx + dx[j];
          int ny = cy + dy[j];
          if ((inBoard(nx, ny)) &&
              (dist[nx][ny] == INF) && // まだ通っていない
              (time < meteor[nx][ny])) // まだ通れる
            {
              if (meteor[nx][ny] == INF) return time;
              dist[nx][ny] = time;
              que.push(make_pair(nx,ny));
            }
        }
      }
  }
  return -1;
}


int main(){
  int x, y, t;  
  scanf("%d", &M);
  
  for (int i=0;i<MAX;i++){
    for (int j=0;j<MAX;j++){
        meteor[i][j] = INF;
        dist[i][j] = INF;
      }
  }

  // 隕石のせいで入れなくなる時刻を記録
  for (int i=0;i<M;i++){
    scanf("%d%d%d", &x, &y, &t);
      for (int j=0;j<5;j++){
        if (inBoard(x+dx[j], y+dy[j])){
          meteor[x+dx[j]][y+dy[j]] = min(meteor[x+dx[j]][y+dy[j]], t);
        }
      }
  }
  cout << solve() << endl;
  
  return 0;
}

