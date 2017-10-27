#include<iostream>
#include<cstdio>
#include<vector>
 
using namespace std; 
 
int par[1001];
int rank[1001];
 
void init(int n) {
  for (int i = 1; i < n+1; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}
 
int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}
 
void unionf(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
 
  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
  }
}
 
int main(){
  struct vertex{
    int x;
    int y;
  };
 
  int n;
  int d;
 
  int a;
  int b;
 
  char op;
 
  vector<int> repair;
  vector<int>::iterator it;
 
  scanf("%d %d",&n,&d);
 
  vertex* v = new vertex[n+1];
 
  for(int i = 1; i < n+1; i++){
    scanf("%d %d",&v[i].x,&v[i].y);
  }
 
  init(n+1);
 
  while(scanf("%c",&op)!=EOF){
    if(op == 'O'){
      scanf("%d",&a);
      for(it = repair.begin(); it != repair.end(); it++){
	if(d*d >= (v[(*it)].x - v[a].x ) * (v[(*it)].x - v[a].x) +(v[(*it)].y - v[a].y ) * (v[(*it)].y - v[a].y)){
	  unionf((*it),a);
	}
      }
      repair.push_back(a);
    }else if(op == 'S'){
      scanf("%d %d",&a,&b);
      if(find(a)==find(b)){
	printf("SUCCESS\n");
      }else{
	printf("FAIL\n");
      }
    }
  }
  delete[] v;
}
