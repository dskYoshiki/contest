//Time Limit Exceeded
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
     
int M;
int meteor[302][302];
int dist[302][302];
// int dx[5] = {0, 0, 0, -1, 1};
// int dy[5] = {0, 1, -1, 0, 0};
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
const int INF = 1<<30;
     
inline bool inBoard(int x, int y)
{
  return (0 <= x && x <= 300 && 0 <= y && y <= 300);
}
     
int main()
{
  int x, y, t;
     
  scanf("%d", &M);
     
  for (int i=0;i<=302;i++)
    for (int j=0;j<=302;j++)
      {
        meteor[i][j] = INF;
        dist[i][j] = INF;
      }
     
  // 隕石のせいで入れなくなる時刻を記録
  for (int i=0;i<M;i++)
    {
      scanf("%d%d%d", &x, &y, &t);
      for (int j=0;j<5;j++)
        if (inBoard(x+dx[j], y+dy[j]))
          meteor[x+dx[j]][y+dy[j]] = min(meteor[x+dx[j]][y+dy[j]], t);
    }
     
  int time = 0;
  int cx = 0, cy = 0;           // current place
  queue<pair<int,int> > que;
  if (meteor[0][0] == 0){
      printf("-1\n");
      return 0;
    }  
  if (meteor[0][0] == INF)
    {
      printf("0\n");
      return 0;
    }
     
  dist[0][0] = 0;
  que.push(make_pair(0,0));
     
  while (!que.empty())
    {
      pair<int,int> cur = que.front();
      que.pop();
      cx = cur.first;
      cy = cur.second;
      if (dist[cx][cy] < meteor[cx][cy])
        {
          time = dist[cx][cy] + 1;
          for (int j=1;j<5;j++)
            {
              int nx = cx + dx[j];
              int ny = cy + dy[j];
              if (inBoard(nx, ny) &&
                  dist[nx][ny] == INF && // まだ通っていない
                  time < meteor[nx][ny]) // まだ通れる
                {
                  if (meteor[nx][ny] == INF)
                    {
                      printf("%d\n", time);
                      return 0;
                    }
                  que.push(make_pair(nx,ny));
                  dist[nx][ny] = time;
                }
            }
        }
    }
  printf("-1\n");
  return 0;
}

