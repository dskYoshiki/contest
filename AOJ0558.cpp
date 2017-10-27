#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
     
typedef pair<int,int> P;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
     
int H, W, N;
char area[1001][1001];
int dist[1001][1001];
int sx, sy;
     
int bfs(){
  char target;
  int sum = 0;
     
  for (int n=1; n<=N; n++) {
    target = n + '0';
    memset(dist, -1, sizeof(dist));
     
    queue<P> que;
    que.push(P(sx,sy));
    dist[sx][sy] = 0;
     
    while (que.size()) {
      P p = que.front();
      if (target == area[p.first][p.second]) {
        sum += dist[p.first][p.second];
        sx = p.first;
        sy = p.second;
        break;
      }
      que.pop();
     
      for (int i=0; i<4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
     
        if (area[nx][ny] != 'X' && dist[nx][ny] == -1 &&
            nx >= 0 && nx < W && ny >= 0 && ny < H) {
          que.push(P(nx,ny));
          dist[nx][ny] = dist[p.first][p.second] + 1;
        }
      }
    }
  }
  return sum;
}
     
int main()
{
  cin >> H >> W >> N;
     
  for (int y=0; y<H; y++) {
    for (int x=0; x<W; x++) {
      cin >> area[x][y];
      if (area[x][y] == 'S') {
        sx = x;
        sy = y;
      }
    }
  }
     
  cout << bfs() << endl;
}

