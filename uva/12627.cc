#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
typedef long long ll;
ll m[5][67];
ll qiuzhi(int k,int f)
{
  if(m[k][f]>0)
   return m[k][f];
  ll p=(f%2==1)? 2*qiuzhi(k,f+1) : qiuzhi(k-1,f/2);
   return p; 
}
ll solve(int k,int a,int b)
{
  ll sum=0;
  if(a==b)
   sum=qiuzhi(k,a);
  else
  {
   int a1=(a%2==1)? a:a+1;
   int b1=(b%2==0)? b:b-1;
   if(b1>a1)
    sum+=3*solve(k-1,(a1+1)/2,b1/2);
   if(a1!=a)
    sum+=qiuzhi(k,a);
   if(b1!=b)
    sum+=qiuzhi(k,b);          
  }
  return sum;
}
int main()
{
  int n;
  scanf("%d",&n);
  memset(m,-1,sizeof(m));
  m[0][1]=1;
  for(int i=0;i<5;i++)
    for(int j=1;m[i][j]>0;j++)
    {
       m[i+1][j*2]=m[i][j];
       m[i+1][j*2-1]=m[i][j]*2;
    }
  //init 
  for(int i=1;i<=n;i++)
  {
    int K,A,B; 
    scanf("%d%d%d",&K,&A,&B);
    printf("Case %d: %lld\n",i,solve(K,A,B));
  } 
  return 0;
}
