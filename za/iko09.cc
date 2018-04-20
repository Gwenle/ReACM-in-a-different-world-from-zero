#include<cstdio>
#include<algorithm>
using namespace std;
#define maxs 150000+300
int bcj[maxs];
void init()
{
  for(int i=0;i<=maxs-200;i++)
     bcj[i]=i;
}
int fint(int m)
{
  if(m!=bcj[m])
    m=fint(bcj[m]); 
  return m;
}
void combine(int a,int b)
{
  int a1=fint(a);
  int b1=fint(b);
  if(a1!=b1)
     bcj[a1]=b1;
}
bool same(int a,int b)
{
  return fint(a)==fint(b);
}
int main()
{
  int N,K;
  while(scanf("%d%d",&N,&K)==2)
  {
    int ans=0;
    int D,X,Y;
    init();
    while(K--)
    {
      scanf("%d%d%d",&D,&X,&Y);
      if(X>N||Y>N)
      {
        ans++;
        continue;
      }
      if(D==1)
      {
        if(same(X,Y+N)||same(X,Y+2*N))
        {
          ans++;
          continue;
        }
        combine(X,Y);
        combine(X+N,Y+N);
        combine(X+2*N,Y+2*N);
      }
      if(D==2)
      {
        if(X==Y||same(X,Y+2*N)||same(X,Y))
        {
          ans++;
          continue;
        }
        combine(X,Y+N);
        combine(Y,X+2*N);
        combine(Y+2*N,X+N);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
