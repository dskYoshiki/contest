#include <iostream>
#include <cstdio>
using namespace std;
     
const int MAX_W = 20;
const int MAX_H = 20;
char room[MAX_W][MAX_H];
int res = 0;
int width;
int height;
     
//現在位置(x, y)
void dfs(int x, int y){
  //今いるところを.に置き換える
  room[x][y] = '#';
  res++;
     
  //移動する4方向をループ
  for(int dx = -1;dx <= 1; dx++){
    //x方向にdx,y方向にdy移動した場所を(nx, ny)とする
    int nx = x + dx, ny = y;
     
    //nxとnyが部屋の範囲内かどうかとroom[nx][ny]が黒いタイルかどうかを判定
    if(0<=nx && nx < width && 0<= ny && ny < height &&room[nx][ny] == '.') dfs(nx, ny);
  }
  for(int dy = -1;dy <= 1; dy++){
    //x方向にdx,y方向にdy移動した場所を(nx, ny)とする
    int nx = x, ny = y + dy;
     
    //nxとnyが部屋の範囲内かどうかとroom[nx][ny]が黒いタイルかどうかを判定
    if(0<=nx && nx < width && 0<= ny && ny < height &&room[nx][ny] == '.') dfs(nx, ny);
  }
  return;
}
     
void solve(int x, int y){
  res = 0;			 
  dfs(x, y);
  printf("%d\n", res);
}
     
int main()
{
  int x, y;
  while (1) {
    cin >> width >> height;
    if(width ==0) break;
    for (int j = 0; j < height; j++) {
      for (int i = 0; i < width; i++) {
        cin >> room[i][j];
        if (room[i][j] == '@'){
          x = i;
          y = j;
        }
      }
    }
    solve(x, y);
    for (int j = 0; j < MAX_H; j++) {
      for (int i = 0; i < MAX_W; i++) {
        room[i][j] == NULL;
      }
    }
  }
  return 0;
}

