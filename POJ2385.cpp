#include<iostream>
#include<algorithm>
     
using namespace std;
     
//二次元配列
template< class T > class Array2D {
public:
  Array2D(const int arrayWidth, const int arrayHeight) {
    msize0 = arrayWidth;
    msize1 = arrayHeight;
    mArray = new T[ msize0 * msize1 ];  
  }
  ~Array2D() {
    delete[] mArray;
    mArray = 0;
  }
     
  T& operator()(const int x, const int y) {
    if ( x >= 0 && x < msize0 && y >= 0 && y < msize1 ) {
      return mArray[msize0 * y + x];
    } else {
      // // 範囲外エラーの処理書く 例えば
      // cout << "( " << x << ", " << y << ")は範囲外を触ってるよ" << endl;
      // exit(1);
    }
  }
  const T& operator()(const int x, const int y) const {
    if ( x >= 0 && x < msize0 && y >= 0 && y < msize1 ) {
      return mArray[msize0 * y + x];
    } else {
      // // 範囲外エラーの処理書く 例えば
      // cout << "( " << x << ", " << y << ")は範囲外を触ってるよ" << endl;
      // exit(1);
    }
  }
     
private:
  T* mArray;  // ２次元配列の本体
  int msize0; // 配列の列の長さ
  int msize1; // 配列の行の長さ
};
     
     
     
/*
  入力
  t:リンゴが落ち続ける時間
  w:Bessieが移動できる回数
  fall:どちらの木からリンゴが落ちるか
  fall[j] = 0のとき, j分後に木1からリンゴが落ちる
  fall[j] = 1のとき, j分後に木2からリンゴが落ちる
     
  出力
  Bessieがキャッチ可能なリンゴの数の最大値
*/
int solve(int t, int w,int* fall)
{
  int res = 0;
  Array2D<int> dp(w+1, t+1);
     
     
  //dpテーブルの１行目を計算
  dp(0,0) = 0;
     
  for(int j = 1; j < t+1; j++){
    if(fall[j] == 0) //j分に木1からリンゴが落ちる
      dp(0,j) = dp(0,j-1) + 1;
     
    else //j分に木1からリンゴが落ちない
      dp(0,j) = dp(0,j-1);    
     
  }
     
     
  //範囲1 <= i <= jのdpテーブルを計算
  for(int i = 1; i < w+1; i++){
    //対角成分の計算
    dp(i,i) = dp(i-1,i-1);
     
    if(fall[i] == (i % 2)) //自分がいる場所にリンゴが落ちてきたとき
      dp(i,i)++;
     
    for(int j = i+1; j < t+1; j++){
     
      dp(i,j) = max(dp(i,j-1), dp(i-1,j-1));
     
      if(fall[j] == (i % 2)) //自分がいる場所にリンゴが落ちてきたとき
    	dp(i,j)++;
     
    }
    //dpの列tから最大値を探す
    if(res < dp(i,t))
      res = dp(i,t);   
  }
     
  return res;
     
}
     
//入力受け取ってsolveに渡して出力するだけ     
int main()
{
  int t, w, tmp;
     
  int* fall;
     
  cin >> t >> w;
     
     
  fall = new int[t+1];
     
  for(int i = 1; i <= t; i++){
    cin >> tmp;    
    fall[i] = tmp-1;//後で計算しやすいように-1して格納しておく
  }
  cout << solve(t, w, fall) << endl;
     
  delete(fall);
     
  return 0;
     
}

