//AOJ
#include <cstdio>
#include <iostream>

using namespace std;
const int N = 3001;

void solve(int A, int B, int C, int D, int E, int F){
  int Num_A = F/(A*100);
  int Num_B = F/(B*100);
  int Num_C = F/C;
  int Num_D = F/D;
  int Num_dp1 = Num_A * Num_B;
  int Num_dp2 = Num_C * Num_D;
  int dp1[Num_dp1];
  int dp2[Num_dp2];
  // int dp1[]={10, 20, 30, 40, 50};
  // int dp2[]={1, 2, 3};
  int k = 0;
  int l = 0;
  for(int i=0;i<Num_A;i++){
    for(int j=0;j<Num_B;j++){
      dp1[k] = (A*i + B*j)*100;
      k++;
    }
  }
  for(int i=0;i<Num_C;i++){
    for(int j=0;j<Num_D;j++){
      dp2[l] = C*i + D*j;
      l++;
    }
  }
  //cout << " a" << endl;
  double ans[2];
  ans[0] = 10000000000;
  ans[1] = 0;
  //cout<< ans[0] << " " << ans[1] << endl;
  //for(int i=0;i<l-1;i++) cout << " " << dp2[i];
  for(int i=0;i<k;i++){cout<< ans[0] << " " << ans[1] << endl;
    for(int j=0;j<l;j++){
      if((dp1[i]*E)/100 >= dp2[j]){ //食塩水に含まれる塩の最大値 >= 入れた塩の量
      double noudo = ans[1]/ans[0];
      double nn = double(dp2[j])/(dp1[i]+dp2[j]);
      // cout << dp1[i] << " " <<dp2[j] << endl;
      // cout << noudo <<" " << nn << endl;
        if(noudo < nn){
          ans[0] = dp1[i] + dp2[j];
          ans[1] = dp2[j];
          cout<< ans[0] << " " << ans[1] << endl;
        }
      }
    }
  }
  cout<< ans[0] << " " << ans[1] << endl;
}

int main(){
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  solve(A, B, C, D, E, F);
  return 0;
}
