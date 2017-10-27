#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace::std;
 
struct edge {int u, v, cost;};
 
bool comp(const edge& e1, const edge& e2){
  return e1.cost > e2.cost;
}
 
int par[1001];
 
void init_union_find(int n){
  for(int i=0; i<n; i++) par[i]=i;
}
 
int find_root(int x){
  if(par[x]==x) return x;
  else return par[x] = find_root(par[x]);
}
 
void unite_tree(int x, int y){
  x = find_root(x);
  y = find_root(y);
  if(x==y) return;
  par[x] = y;
}
 
bool same_tree(int x, int y){
  return  find_root(x)== find_root(y);
}
 
int kruskal(int n,int m,edge es[]){
  int res = 0;
  int count = 0;
  for(int i=0; i<m; i++){
    if(!same_tree(es[i].u, es[i].v)){
      unite_tree(es[i].u, es[i].v);
      res += es[i].cost;
      count++;
    }
  }
  if(count == n-1) return res;
  return -1;
}
 
int main(){
  int n,m;
 
  scanf("%d %d",&n,&m);
 
  init_union_find(n);
  edge* es = new edge[m];
 
  for(int i = 0; i < m; i++) 
    scanf("%d %d %d",&es[i].u, &es[i].v, &es[i].cost);
 
  sort(es, es+m, comp);
  printf("%d\n",kruskal(n, m, es));
}
