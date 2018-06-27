#include<cstdio>
#include<cstring>
using namespace std;
int re[1010];
int be[1010];
int find(int e)
{
  if(re[e]<0||re[e]==e)
    return re[e];
  re[e]=find(re[e]);
  return re[e];
}
void combine(int a,int b) //head is b1
{
  int a1=find(a);
  int b1=find(b);
  if(a1!=b1)
   re[a1]=b1;
}
int main()
{
  int N,M,X,Y;
  while(scanf("%d%d%d%d",&N,&M,&X,&Y)==4)
  {
    bool ok=true;
    memset(be,0,sizeof(be));
    for(int i=1;i<=N;i++)
      re[i]=i;
    for(int i=0;i<M;i++)
    {   
      int a,b;
      scanf("%d%d",&a,&b);
      int a1=find(a);
      int b1=find(b);
      if(a1==b1)
        ok=false;
      if(be[a1]==0)
         be[a1]=b1;
      else
         combine(b,be[a1]);
      if(be[b1]==0)
         be[b1]=a1;
      else
         combine(a,be[b1]);
    }
    //wrong
    for(int i=0;i<X;i++)
    {
      int a;
      scanf("%d",&a);
      int a1=find(a);
      if(a1==-1)
       continue;
      if(a1==-2)
      { ok=false; continue;}
      int a2=be[a1];
      if(re[a2]==-1)
      { ok=false; continue;}
      re[a1]=-1;
      re[a2]=-2;
    }
    for(int i=0;i<Y;i++)
    {
      int b;
      scanf("%d",&b);
      int b1=find(b);
      if(b1==-2)
       continue;
      if(b1==-1)
      { ok=false; continue;}
      int b2=be[b1];
      if(re[b2]==-2)
      { ok=false; continue;}
      re[b1]=-2;
      re[b2]=-1;
    }
    for(int t=1;t<=N;t++)
    {
       int t1=find(t);
       if(t1<0)
        continue;
       else if(be[t1]==0)
        ok=false;
    }
    if(ok)
     printf("YES\n");
    else
     printf("NO\n");
  }
  return 0;
}
