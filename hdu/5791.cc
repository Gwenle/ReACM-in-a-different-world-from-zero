#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[1010][1010];
int a[1010];
int n,m;
int b[1010];
const ll mod=1000000007;
ll gouzao(unsigned int f,unsigned int t)
{
  if(f==0||t==0)
   return 0;
  if(dp[f][t]!=-1)
   return dp[f][t];
  if(a[f-1]==b[t-1])
  {
   dp[f][t]=(gouzao(f-1,t)%mod+gouzao(f,t-1)%mod+1)%mod;
  }
  else
   dp[f][t]=(mod+gouzao(f-1,t)%mod+gouzao(f,t-1)%mod-gouzao(f-1,t-1)%mod)%mod;
  return dp[f][t];
}
int main()
{
   while(scanf("%d%d",&n,&m)==2)
   {
      for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
      for(int i=0;i<m;i++)
       scanf("%d",&b[i]);
      memset(dp,-1,sizeof(dp));
      printf("%lld\n",(gouzao(n,m))%mod);
   }
   return 0;
}
