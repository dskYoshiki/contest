#include <iostream>
     
using namespace std;
     
int solve(int* pack, int ans){
     
  if(pack[6] != 0){//6*6の製品を詰める
    ans = ans + pack[6];
    pack[6] = 0;
  }
  if(pack[5] != 0){//5*5の製品を詰める
    ans = ans + pack[5];
    if(pack[1] <= pack[5] * 11){
      pack[1] = 0;
    }
    else{
      pack[1] = pack[1] - (pack[5] * 11);
    }
  }
  if(pack[4] != 0){//4*4の製品を詰める
    ans = ans + pack[4];
    if(pack[2] <= pack[4] * 5){
      if(pack[1] <= (36 * pack[4]) - (pack[2] * 4) - (pack[4] * 16) ){
        pack[1] = 0;
      }
      else{
        pack[1] = pack[1] - ( (36 * pack[4]) - (pack[2] * 4) - (pack[4] * 16) );
      }
      pack[2] = 0;
    }
    else pack[2] = pack[2] - (pack[4] * 5);
    pack[4] = 0;
  }
  if(pack[3] != 0){//3*3の製品を詰める
     
    if(pack[3] % 4 == 0){
      ans += pack[3] / 4;
    }
    else{
      ans += (pack[3] / 4) + 1;
    }
     
    pack[3] = pack[3] % 4;
     
    if(pack[3] != 0){
     
      if(pack[2] <= 7 - pack[3] * 2){
        if(pack[1] <= (36 - pack[3] * 9) - pack[2] * 4 ){
          pack[1] = 0;
        }
        else{
          pack[1] = pack[1] - ( (36 - pack[3] * 9) - (pack[2] * 4) );
        }
        pack[2] = 0;
      }
      else{
     
        pack[2] = pack[2] - (7 - pack[3] * 2);
     
        if(pack[1] <= (36 - pack[3] * 9) - ( (7 - pack[3] * 2)  * 4 ) ){
          pack[1] = 0;
        }
        else{
          pack[1] = pack[1] - ( (36 - pack[3] * 9) - ( (7 - pack[3] * 2) * 4 ) );
        }
      }
      pack[3] = 0;
    }
     
  }
  if(pack[2] != 0){//2*2の製品を詰める
    if(pack[2] % 9 == 0){
      ans += pack[2] / 9;
    }
    else{
      ans += (pack[2] / 9) + 1;
    }
    pack[2] = pack[2] % 9;
    if(pack[2] != 0){
      if(pack[1] <= 36 - pack[2] * 4){
        pack[1] = 0;
      }
      else pack[1] = pack[1] - (36 - pack[2] * 4);
    }
    pack[2] = 0;
  }
  if(pack[1] != 0){//1*1の製品を詰める
    if(pack[1] % 36 == 0){
      ans += pack[1] / 36;
    }
    else{
      ans += (pack[1] / 36) + 1;
    }
    pack[1] = 0;
  }
     
  return ans;
}
     
int main(){
     
  int pack[7] = {0};
     
  while(1){
     
    for(int i = 1; i <= 6; i++){
      cin >> pack[i];
    }
    if((pack[1]==0) && (pack[2]==0) &&(pack[3]==0) &&(pack[4]==0) &&(pack[5]==0) &&(pack[6]==0)) break;
     
    cout << solve(pack, 0) << endl;
     
  }
     
  return 0;
     
}

