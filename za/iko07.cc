#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int re[120];
int sh[120];
int fint(int x)
{
  while(x!=re[x])
    x=re[x];
  return x;
}
void combine(int x1,int x2)
{
   int t1=fint(x1);
   int t2=fint(x2);
   if(sh[t1]==sh[t2]&&x1>x2)
     swap(t1,t2);
   if(sh[t1]>sh[t2])
     swap(t1,t2);
   if(t2!=t1)
   {
      re[t1]=t2;
      sh[t2]=sh[t1]+sh[t2];
   }
}
int main()
{
  int M,N,sk=0;
  while(scanf("%d%d",&N,&M)==2)
  {
    sk++;
    memset(re,0,sizeof(re));
    memset(sh,0,sizeof(sh));
    for(int i=1;i<=N;i++)
    {
      re[i]=i;
      sh[i]=1;
    }
    while(M--)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      combine(a,b);
    }
    int p;
    scanf("%d",&p);
    printf("Case %d:\n",sk);
    while(p--)
    {
      int v;
      scanf("%d",&v);
      int vt=fint(v);
      printf("%d %d\n",vt,sh[vt]);
    }
  }
  return 0;
}
