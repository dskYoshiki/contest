#include <cstdio>
#include <vector>
#include <algorithm>
     
using namespace std;
     
class Block{
public:
  Block(){}
  Block(int h, int a, int c): h(h), a(a), c(c) {}
  bool operator<(const Block& b) const {
    return a < b.a;
  }
     
  int h;
  int a;
  int c;
};
     
vector<Block> blocks;
     
int slove(int K){
  int ans = 0;
  bool dp[40001];
  dp[0] = true;
  sort(blocks.begin(), blocks.end());
     
  for (int i = 0; i < K; i++) {
    for (int j = ans; j >= 0; j--) {
      if ( dp[j] ) {
        for (int k = 1; k <= blocks[i].c; k++) {
          if ( j + k*blocks[i].h > blocks[i].a )
            break;
          dp[j + k*blocks[i].h] = true;
          ans = max(ans, j + k*blocks[i].h);
        }
      }
    }
  }
     
  return ans;
}
     
int main(){
  int K;
  scanf("%d", &K);
  for (int i = 0; i < K; i++) {
    int h, a, c;
    scanf("%d %d %d", &h, &a, &c);
    blocks.push_back(Block(h, a, c));
  }
     
  printf("%d\n", slove(K));
}

