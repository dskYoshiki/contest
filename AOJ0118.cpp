#include <cstdio>
#include <iostream>
using namespace::std;
const int MAX_N=100;
char field[MAX_N][MAX_N + 1];	//果樹園
int M, N;
     
//現在位置(x, y)
void dfs(int x, int y, char fu){
  //今いるところを.に置き換える
  field[x][y] = '.';
  //上下左右を調べる。
  //nxとnyが庭の範囲内かどうかとfield[nx][ny]が水溜か同じ果物かどうかを判定
  int nx = x-1, ny = y; //左
  if(0<=nx && nx < N && 0<= ny && ny < M &&field[nx][ny] == fu) dfs(nx, ny, fu);
  nx = x, ny = y-1; //上
  if(0<=nx && nx < N && 0<= ny && ny < M &&field[nx][ny] == fu) dfs(nx, ny, fu);
  nx = x+1, ny = y; //右
  if(0<=nx && nx < N && 0<= ny && ny < M &&field[nx][ny] == fu) dfs(nx, ny, fu);
  nx = x, ny = y+1; //下
  if(0<=nx && nx < N && 0<= ny && ny < M &&field[nx][ny] == fu) dfs(nx, ny, fu);
  return;
}
     
void solve(){
  int res = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(field[i][j] != '.'){
        //調査済みでなければ、そこからdfsを始める
        dfs(i, j, field[i][j]);
        res++;
      }
    }
  }
  printf("%d\n", res);
}
     
int main(){
  //入力
  while(1){
    cin >> N >> M; //cinで入力を読み込む
    if(N==0 && M==0) break;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        cin >> field[i][j];
      }
    }
    solve();
  }
  return 0;
}

