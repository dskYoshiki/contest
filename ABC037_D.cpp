#include <cstdio>
#include <vector>
#include <algorithm>
     
#define QUOTIENT 1000000007
     
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
  }private:
  T* mArray;  // ２次元配列の本体
  int msize0; // 配列の列の長さ
  int msize1; // 配列の行の長さ
};
     
     
typedef struct elements{//x行i列の要素がvalue
     
  int value,x,y;
     
  //オーバーロード
  bool operator < (const struct elements &e) const
  {
    return value < e.value;	
  }
  bool operator > (const struct elements &e) const
  {
    return value < e.value;	
  }
     
} elements;
     
     
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
     
     
int solve(int h, int w, Array2D<int> &grid, elements* tree_ordering)
{
  sort(tree_ordering, tree_ordering + w * h);//valueの値でソート
     
  int res = 0;
  Array2D<int> total_way(h, w);
     
  for(int i = 0; i < w * h; i++){
    int x = tree_ordering[i].x;
    int y = tree_ordering[i].y;
     
    for(int j = 0; j < 4; j++){
      if(x + dx[j] >= 0 && x + dx[j] < h && y + dy[j] >= 0 && y + dy[j] < w)
        //i行j列へ移動できるマスを終点とする移動経路を足し合わせる
    	if(grid(x + dx[j], y + dy[j]) < grid(x,y))
    	  total_way(x, y ) =
    	    (total_way(x, y) + total_way(x + dx[j], y + dy[j]) ) % QUOTIENT;
    }
     
    total_way(x,y)++;//自分自身のみの移動経路を加算する
     
    //この時点でi行j列を終点とする移動経路の総数が求め終わってるので答えに加算する
    res = (res + total_way(x,y)) % QUOTIENT;
     
  }
     
  return res;
     
}
     
     
int main(){
  int w,h;
     
  scanf("%d %d",&h, &w);
  Array2D<int> grid(h, w);
  elements* tree_ordering = new elements[h * w];
     
  for (int i=0; i < h; ++i) {
    for (int j=0; j < w; ++j) {
      int c;
      scanf("%d",&c);
      grid(i,j) = c;
      tree_ordering[w*i+j].value = c;
      tree_ordering[w*i+j].x = i;
      tree_ordering[w*i+j].y = j;
    }
  }
     
  printf("%d\n", solve(h, w, grid, tree_ordering));
  delete(tree_ordering);
     
}

