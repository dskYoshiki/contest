#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  string str;
  cin >> str;
  int count=0;
  for(int i = 0; i < (int)str.size(); ++i){
    char ch = str[i];
    if(int(ch)=='1') count++;
  }
  cout << count << endl;
  return 0;
}
