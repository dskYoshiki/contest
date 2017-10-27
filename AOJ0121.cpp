#include <cstdio>
#include <map>
#include <queue>
#include <string>
     
using namespace std;
     
int direction[] = {1, -1, 4, -4};
map<string, int> done;
     
// 01234567から遷移できる全ての状態を列挙する関数
void makeStatus(){
  queue<string> q;
  q.push("01234567");
  done["01234567"] = 0;
     
  while ( q.size() ) {
    string s = q.front();
    q.pop();
    int x = s.find('0');
    for (int i = 0; i < 4; i++) {
      if ( x+direction[i] >=0 && x+direction[i] < 8 ) {
        if ( x == 3 && i == 0 || x == 4 && i == 1 ) continue;
        string temp = s;
        swap(temp[x], temp[x+direction[i]]);
        map<string, int>::iterator it;
        it = done.find(temp);
        if ( it == done.end() ) {
          int counter = done[s];
          done[temp] = counter+1;
          q.push(temp);
        }
      }
    }
  }
}
     
int solve(char* puzzle){
  string req;
  for (int i = 0; i < 8; i++) {
    req.push_back(puzzle[i]);
  }
  return done[req];
}
     
int main(){
  makeStatus();
     
  char puzzle[8];
  while ( scanf(" %c %c %c %c %c %c %c %c ",
                &puzzle[0], &puzzle[1], &puzzle[2], &puzzle[3],
                &puzzle[4], &puzzle[5], &puzzle[6], &puzzle[7]) != EOF ) {
    printf("%d\n", solve(puzzle));
  }
}

