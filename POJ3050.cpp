#include<cstdio>
#include<iostream>
#include<map>
#include<math.h>
     
using namespace std; 
     
int a[5][5];
int y = 0;
map<int,int> value;
map<int,int>::const_iterator itr;
     
void solve(int i,int j,int tmp[],int k){
  if(k < 5){
    tmp[k] = a[i][j];
    if(i != 0) solve(i-1,j,tmp,k+1);
    if(j != 4) solve(i,j+1,tmp,k+1);
    if(i != 4) solve(i+1,j,tmp,k+1);
    if(j != 0) solve(i,j-1,tmp,k+1);
  }else{
    int res;
    tmp[k] = a[i][j];
    res = 0;
    res += tmp[0];
    res += tmp[1]*10;
    res += tmp[2]*100;
    res += tmp[3]*1000;
    res += tmp[4]*10000;
    res += tmp[5]*100000;
    if (value.find(res) == value.end()){
      value.insert( map<int, int>::value_type(res, res));
      y++;
    }
  }
}
     
int main(){
     
  int tmp[6] = {0,0,0,0,0,0};
     
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> a[i][j];
    }
  }
     
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      solve(i,j,tmp,0);
    }
  }
     
  cout << y << endl;
}

