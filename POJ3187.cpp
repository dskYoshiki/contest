#include<iostream>
#include<vector>
#include<algorithm>
     
using namespace std;
     
     
int* c;
     
int getBackwardDigitSums(vector<int> &sequence)
{
  int l = sequence.size();
  int sum = sequence[0];
     
  for(int i = 1; i < l; i++)
    sum += c[i] * sequence[i];
     
  return sum;
     
}
     
     
vector<int> solve(int n, int s)
{
  vector<int> sequence;
     
  for(int i = 0; i < n; i++)
    sequence.push_back(i+1);
     
  c = new int[n];
     
  c[0] = 1;
     
  for(int i = 1; i < n; i++)
    c[i] = c[i-1] * (n - i)/ i;
     
  do{
     
    if(getBackwardDigitSums(sequence) == s)
      return sequence;
     
  }while( next_permutation(sequence.begin(), sequence.end() ));
     
  delete c;
     
  return sequence;
}
     
     
int main(){
  int n, s;
     
  cin >> n >> s;
     
  vector<int> sequence = solve(n,s);
     
  for(int i = 0; i < sequence.size(); i++)
    cout << sequence[i]<< " ";
     
  cout << endl;
     
}

