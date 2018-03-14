#include<cstdio>
#include<queue>
using namespace std;
int main()
{
  int n;
  while(scanf("%d",&n)==1&&n!=0)
  {
     priority_queue<int, vector<int>,greater<int> > ma;
     for(int i=0;i<n;i++)
     {
       int k;
       scanf("%d",&k);
       ma.push(k);
     }
     long long ans=0;
     while(ma.size()>1)
     {
       int a=ma.top();
       ma.pop();
       int b=ma.top();
       ma.pop();
       ans+=a+b;
       ma.push(a+b);
     }
     printf("%lld\n",ans);
  }
  return 0;
} 
