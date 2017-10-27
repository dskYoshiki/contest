#include <iostream>
     
using namespace std;
     
int w, h;
int board[21][21];
int ans;
     
//移動回数,現在のマス(x,y),進む方向
void dfs(int n, int x, int y, int way) {
  if (n >= ans) return;
     
  for (int i=0; i<1; i++) {
    int mx=x, my=y;
     
    //下方向
    if (way == 1){
      mx += 0; my += -1;
      if (mx < 0 || mx >= w) { continue; }
      if (my < 0 || my >= h) { continue; }
      if (board[my][mx] == 1) { continue; }
     
      while (1) {
        if (board[my][mx] == 3) {
          ans = n;
          return;
        }
     
        mx += 0; my += -1;
        if (mx < 0 || mx >= w) { break; }
        if (my < 0 || my >= h) { break; }
     
        if (board[my][mx] == 1) {
          board[my][mx] = 0;
          dfs(n+1, mx, my+1, 1);
          dfs(n+1, mx, my+1, 2);
          dfs(n+1, mx, my+1, 3);
          dfs(n+1, mx, my+1, 4);
          board[my][mx] = 1;
          break;
        }
      }
    }
     
    //上方向
    if (way == 2){
      mx += 0; my += 1;
      if (mx < 0 || mx >= w) { continue; }
      if (my < 0 || my >= h) { continue; }
      if (board[my][mx] == 1) { continue; }
     
      while (1) {
        if (board[my][mx] == 3) {
          ans = n;
          return;
        }
     
        mx += 0; my += 1;
        if (mx < 0 || mx >= w) { break; }
        if (my < 0 || my >= h) { break; }
     
        if (board[my][mx] == 1) {
          board[my][mx] = 0;
          dfs(n+1, mx, my-1, 1);
          dfs(n+1, mx, my-1, 2);
          dfs(n+1, mx, my-1, 3);
          dfs(n+1, mx, my-1, 4);
          board[my][mx] = 1;
          break;
        }
      }
    }
     
    //左方向
    if (way == 3){
      mx +=-1; my += 0;
      if (mx < 0 || mx >= w) { continue; }
      if (my < 0 || my >= h) { continue; }
      if (board[my][mx] == 1) { continue; }
     
      while (1) {
        if (board[my][mx] == 3) {
          ans = n;
          return;
        }
     
        mx += -1; my += 0;
        if (mx < 0 || mx >= w) { break; }
        if (my < 0 || my >= h) { break; }
     
        if (board[my][mx] == 1) {
          board[my][mx] = 0;
          dfs(n+1, mx+1, my, 1);
          dfs(n+1, mx+1, my, 2);
          dfs(n+1, mx+1, my, 3);
          dfs(n+1, mx+1, my, 4);
          board[my][mx] = 1;
          break;
        }
      }
    }
     
    //右方向
    if (way == 4){
      mx += 1; my += 0;
      if (mx < 0 || mx >= w) { continue; }
      if (my < 0 || my >= h) { continue; }
      if (board[my][mx] == 1) { continue; }
     
      while (1) {
        if (board[my][mx] == 3) {
          ans = n;
          return;
        }
     
        mx += 1; my += 0;
        if (mx < 0 || mx >= w) { break; }
        if (my < 0 || my >= h) { break; }
     
        if (board[my][mx] == 1) {
          board[my][mx] = 0;
          dfs(n+1, mx-1, my, 1);
          dfs(n+1, mx-1, my, 2);
          dfs(n+1, mx-1, my, 3);
          dfs(n+1, mx-1, my, 4);
          board[my][mx] = 1;
          break;
        }
      }
    }
  }
}
     
int main() {
  while (cin >> w >> h, (w || h)) {
    int sx, sy;
    for (int y=0; y<h; y++) {
      for (int x=0; x<w; x++) {
        cin >> board[y][x];
        if (board[y][x] == 2) {
          sx = x; sy = y;
        }
      }
    }
     
    ans = 11;
    dfs(1, sx, sy, 1);
    dfs(1, sx, sy, 2);
    dfs(1, sx, sy, 3);
    dfs(1, sx, sy, 4);
    if (ans > 10) ans = -1;
    cout << ans << endl;
  }
     
  return 0;
}

