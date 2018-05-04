#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
long long m[550];
//first algorithm version is wrong
//because maximum number of pages assigned to a single scriber cannot be calculated
int a,b;
bool opos(ll o)
{
  int p=b-1;
  ll tem=m[a-1];
  for(int i=a-2;i>=0;i--)
  {
    tem=tem+m[i];
    if(tem>o)
    {
      p--;
      tem=m[i]; 
    }
    if(p<0)
     return false;
  }
  if(p>=0)
     return true;
  else
     return false;
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d%d",&a,&b);
    ll sum=0;
    for(int i=0;i<a;i++)
    {
      scanf("%lld",&m[i]);
      sum+=m[i];
    }
    ll avg=sum/b;
    while(sum-avg>1)
    {
       ll ap=(avg+sum)/2;
       if(opos(ap))
        sum=ap;
       else
        avg=ap;
    }
    ll op=(opos(avg))? avg:sum;
    stack<int> z;
    ll at=m[a-1];
    int q=b-1;
    for(int i=a-2;i>=0&&q>0;i--)
    {
       if(q-1==i)
       {
         z.push(i);
         q--;
         continue;
       }
       at+=m[i];
       if(at>op)
       {
         z.push(i);
         q--;
         at=m[i];
       }
    }
    int f=(z.empty())? a:z.top();
    if(!z.empty()) z.pop();
    for(int i=0;i<a;i++)
    {
      if(i!=0)
       printf(" ");
      printf("%lld",m[i]);
      if(i==f)
      { 
        printf(" /");
        if(!z.empty())
        {
           f=z.top();
           z.pop();
        }
      }
    }
    printf("\n");
  }
  return 0;
}
