#include<iostream>
#include<cstdio>
#include<map>
#include<time.h>
     
using namespace std; 
     
int main(){
  clock_t st = clock();
     
  int c;
  int n;
     
  int a[20][2];
  map<int,int> coin;
  map<int,int>::reverse_iterator ritr;
  map<int,int>::iterator itr;
     
  int tmp = 0;
  int res = 0;
     
  bool done = false;
     
  scanf("%d %d",&n,&c);
     
  for(int i = 0; i < n; i++){
    scanf("%d %d",&a[i][0],&a[i][1]);
  }
     
  for(int i = 0; i < n; i++){
    if(a[i][0] < c){
      coin[a[i][0]] = a[i][1];
    }else{
      res += a[i][1];
    }
  }
     
  while(!done){
    for(ritr = coin.rbegin() ; ritr != coin.rend() ;){
      if((*ritr).second == 0||tmp + (*ritr).first >= c){
    	ritr++;
      }else{
    	tmp += (*ritr).first;
    	(*ritr).second--;
      }
    }
     
    for(itr = coin.begin() ; itr != coin.end() ; itr++){
      if((*itr).second > 0){
    	res++;
    	tmp += (*itr).first;
    	(*itr).second--;
    	break;
      }	
    }
     
    if(tmp < c) done = true;
    tmp = 0;
  }
  clock_t ed = clock();
     
  printf("%d\n",res);
  cout << (ed-st) << endl;
}

