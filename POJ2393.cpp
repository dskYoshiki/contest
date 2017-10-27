#include <iostream>
using namespace std;
     
int main()
{
     
  int N, S;
  cin >> N >> S;
  int P = 5000;
  long long cost = 0;
  for (int i = 0; i < N; i++)
    {
      int C, Y;
      cin >> C >> Y;
      P = min(P + S, C);
      cost += P * Y;
    }
  cout << cost << endl;
     
  return 0;
}
