#include <iostream>
#include <vector>
     
using namespace std;
     
int main(){
     
  int n;
  vector<bool> prime;
  int count;
     
  while(cin >> n){
    prime.clear();
    count = 0;
    prime.push_back(false);
    for(int i=1; i<n; i++) prime.push_back(true);
     
    for(int i=1;i<n;i++){
      if(prime[i]){
        count++;
        for(int j=2*(i+1)-1;j<n;j=j+(i+1)){  //エラトステネスの篩
          prime[j] = false;
    	}
      }
    }
    cout << count << endl;
  }
     
  return 0;
}

