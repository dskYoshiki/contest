#include <cstdio>
#include <iostream>

using namespace std;

int alph_table(char alph){
  int suti;
  char table[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  for(int i=0;i<26;i++){
    if(alph == table[i]) suti = i;
  }
  return suti;
}

int final_sort(int n, int* x, int * f){
  int final[n];
  int i, j, temp;
  for(int i=0;i<n;i++){
    final[i] = i;
  }
  
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (x[j - 1] > x[j]) {  /* 前の要素の方が大きかったら */
        temp = x[j];        /* 交換する */
        x[j] = x[j - 1];
        x[j - 1]= temp;
        temp = final[j];        /* 交換する */
        final[j] = final[j - 1];
        final[j - 1]= temp;
      }
    }
  }
  for(int i=0;i<n;i++){
    //cout << "final["<< i << "] = " << final[i] << endl;
    f[i] = final[i];
  }
  return *f;
}

int b_compare(int n, int* x){
  int a_comp = 0;
  int i, j, temp;

  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (x[j - 1] > x[j]) {  /* 前の要素の方が大きかったら */
        temp = x[j];        /* 交換する */
        x[j] = x[j - 1];
        x[j - 1]= temp;
        a_comp++;
      }
    }	
  }
  return a_comp;
}

void solve(int n, int m, string* str){
  int comp[m];
  for(int i=0;i<m;i++){
    int list[n];
    for(int j=0;j<n;j++){
      list[j] = alph_table(str[i][j]); //string型str[i]のj文字目
    }
    comp[i] = b_compare(n, list); //バブルソートの交換回数
  }  
  //交換回数少なかった順に出力 comp[m]
  int f[m];
  int dami[m];
  for(int i=0;i<m;i++){
    dami[i] = comp[i];
  }
  *f = final_sort(m, dami, f);

  for(int i=0;i<m;i++){  //解の出力
    cout << str[f[i]] << endl;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  string str[m];
  for(int i=0;i<m;i++){
    cin >> str[i];
  }
  solve(n, m, str);
  return 0;
}
