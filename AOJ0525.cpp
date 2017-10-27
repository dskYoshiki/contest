#include <iostream>
#include <algorithm>
     
using namespace::std;
     
int ans = 0;
     
void solve(int** osenbei, int** osenbei_extra, int i, const int c, const int r, int temp){
     
  int bef = 0;
  int aft = 0;
  if(i == c){
     
    for(int j = 0; j < c; j++){
      for(int k = 0; k < r; k++){
        osenbei_extra[j][k] = osenbei[j][k];
      }
    }
     
    for(int j = 0; j < r; j++){
     
      int bef = 0;
      int aft = 0;
      for(int k = 0; k < c; k++){//i列目を返す
        if(osenbei_extra[k][j] == 1){
          osenbei_extra[k][j] = 0;
          bef++;//i列目の1の数を調べる
        }
        else{
          osenbei_extra[k][j] = 1;
          aft++;//i列目の0の数を調べる
        }
      }
      if(bef <= aft){
        temp = temp - bef + aft;
        ans = max(ans, temp);
      }
      else{
        for(int k = 0; k < c; k++){//i行目を返し直す
          if(osenbei_extra[k][j] == 1) osenbei_extra[k][j] = 0;
          else osenbei_extra[k][j] = 1;
        }
      }
    }
     
    if(ans < temp){
      ans = temp;
    }
     
  }
  else{
     
    for(int j = 0; j < r; j++){//i行目を返す
      if(osenbei[i][j] == 1){
        osenbei[i][j] = 0;
        bef++;//i行目の1の数を調べる
      }
      else{
        osenbei[i][j] = 1;
        aft++;//i行目の0の数を調べる
      }
    }
     
    solve(osenbei, osenbei_extra, i+1, c, r, temp - bef + aft);
     
    for(int j = 0; j < r; j++){//i行目を返し直す
      if(osenbei[i][j] == 1) osenbei[i][j] = 0;
      else osenbei[i][j] = 1;
    }
     
    solve(osenbei, osenbei_extra, i+1, c, r, temp);
     
  }
}
     
int main(){
     
  while(1){
     
    int temp_c, temp_r;
    cin >> temp_c;//行
    cin >> temp_r;//列
     
    const int r = temp_r;
    const int c = temp_c;
     
    if(c == 0 && r == 0) break;	
     
    int** osenbei = new int*[c];
    int** osenbei_extra = new int*[c];
    for(int i = 0; i < c; i++){
      osenbei[i] = new int[r];
      osenbei_extra[i] = new int[r];
    }
     
    for(int i = 0; i < c; i++){
      for(int j = 0; j < r; j++){
        osenbei[i][j] = 0;
        osenbei_extra[i][j] = 0;
      }
    }
     
    int temp = 0;
    for(int i = 0; i < c; i++){
      for(int j = 0; j < r; j++){
        cin >> osenbei[i][j];
        if(osenbei[i][j] != 0 && osenbei[i][j] != 1) return 1;
        else if(osenbei[i][j] == 1) temp++;
        osenbei_extra[i][j] = osenbei[i][j];
      }
    }
    ans = temp;
     
    solve(osenbei, osenbei_extra, 0, c, r, temp);
    cout << ans << endl;
     
  }
     
  return 0;
     
}

