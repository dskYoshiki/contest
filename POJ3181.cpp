#include<cstdio>
#include<iostream>
     
using namespace std;
     
const long long int MOD=1000000000000000000;
long long int big[1001]={0},small[1001]={0};
     
int main()
{
  int N,K;
  cin >> N >> K;
     
  small[0]=1;
  for(int i=1;i<=K;i++)
    {
      for(int j=i;j<=N;j++)
        {
          big[j]=big[j]+big[j-i]+(small[j]+small[j-i])/MOD;
          small[j]=(small[j]+small[j-i])%MOD;
        }
    }
  if(big[N]) printf("%lld",big[N]);
  printf("%lld\n",small[N]);
  return 0;
}

