#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
     
using namespace std;
     
struct Data_cows
{
  int start, end, number, stall;
     
  bool operator<(const Data_cows& right) const
  {
    if(start == right.start){
      return end > right.end;
    }
    return start < right.start;
  }
};
     
     
bool comp(Data_cows cow1, Data_cows cow2){
  return cow1.number < cow2.number;
}
     
int main()
{
  int n;
  int stallSize;
  cin >> n;
  vector<Data_cows> cow(n);
     
  for(int i=0; i<n; i++)
    {
      cin >> cow[i].start >> cow[i].end;
      cow[i].number = i;
    }
     
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }
     
  sort(cow.begin(), cow.end());
  cow[0].stall = 1;
  stallSize = 1;
     
  priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > stalls;
     
  stalls.push(pair<int,int>(cow[0].end,1));
     
  for(int i = 1; i < n; i++){
    pair<int,int> tmp = stalls.top();
    if(tmp.first < cow[i].start){
      stalls.pop();
      stalls.push(pair<int,int>(cow[i].end,tmp.second));
      cow[i].stall = tmp.second;
    }
     
    else{
      stallSize++;
      stalls.push(pair<int,int>(cow[i].end,stallSize));
      cow[i].stall = stallSize;
    }
  }
     
  sort(cow.begin(), cow.end(), comp);
     
  cout << stallSize << endl;
     
  for(int k = 0; k < n; k++){
    cout << cow[k].stall << endl;
  }
     
  return 0;
     
}

