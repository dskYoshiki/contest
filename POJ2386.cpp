#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N=100;
char field[MAX_N][MAX_N + 1];	//庭
int M, N;
 
 
//現在位置(x, y)
void dfs(int x, int y){
  //今いるところを.に置き換える
  field[x][y] = '.';
 
  //移動する8方向をループ
  for(int dx = -1;dx <= 1; dx++){
    for(int dy = -1;dy <= 1; dy++){
      //x方向にdx,y方向にdy移動した場所を(nx, ny)とする
      int nx = x + dx, ny = y + dy;
 
      //nxとnyが庭の範囲内かどうかとfield[nx][ny]が水溜かどうかを判定
      if(0<=nx && nx < N && 0 <= ny && ny < M && (field[nx][ny] == 'W')) dfs(nx, ny);
    }
  }
  return;
}
 
void solve(){
  int res = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(field[i][j] == 'W'){
        //Wが残っているならそこからdfsを始める
        dfs(i, j);
        res++;
      }
    }
  }
  cout << res << endl;
}
 
int main(){
  //入力
  cin >> N >> M; //cinで入力を読み込む
  for(int i=0 ; i<N ; i++){
    for(int j=0 ; j<M ; j++){
      cin >> field[i][j];
    }
  }
  solve();
  return 0;
}
