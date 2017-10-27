//compile
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
     
vector<int> d;
vector<int> A, B;
int na, nb;
const int inf = 1<<30;
     
int vectoint(vector<int>& A)
{
  int n = 0;
  for (int i=0;i<A.size();i++) n = n * 10 + A[i];
  return n;
}
     
int dfs(int k)
{
  if ((A.size() == na) && (B.size() == nb))
    {
      int mindiff = inf;
      int numa, numb;
      // 全ての順列を出力
      do{
        if (A[0] || (A.size() == 1))
          {
            numa = vectoint(A);
            do{
              if (B[0] || (B.size() == 1))
                {
                  numb = vectoint(B);
                  //cout << numa << ' ' << numb << endl;
                  if (mindiff > abs(numa - numb)) mindiff = abs(numa - numb);
                }
            } while(next_permutation(B.begin(), B.end()));
          }
      } while(next_permutation(A.begin(), A.end()));
     
      return mindiff;
    }
  else if ((A.size() > na) || (B.size() > nb)) return inf;
  else if ((A.size() == na) && (B.size() < nb))
    {
      B.push_back(d[k]);
      int dif_b = dfs(k+1);
      B.pop_back();
      return dif_b;
    }
  else if ((A.size() < na) && (B.size() == nb))
    {
      A.push_back(d[k]);
      int dif_a = dfs(k+1);
      A.pop_back();
      return dif_a;
    }
  else
    {
      A.push_back(d[k]);
      int dif_a = dfs(k+1);
      A.pop_back();
     
      B.push_back(d[k]);
      int dif_b = dfs(k+1);
      B.pop_back();
      return min(dif_a, dif_b);
    }
}
     
int main()
{
  int N;
  cin >> N;
     
  string a;
  getline(cin, a);
  for (int p=0; p<N; p++)
    {
      d.clear();
      A.clear();
      B.clear();
     
      int k = 0;
      getline(cin, a);
      for (int i = 0; i<a.size(); i++)
        {
          if (isdigit(a[i])) d.push_back(a[i]-'0');
        }
     
      na = d.size()/2;
      nb = d.size() - na;
     
      int res = dfs(0);
      cout << res << endl;
    }
     
  return 0;
}

