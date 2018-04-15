#include<cstdio>
#include<cstring>
int m[1010];
int ans;
int fint(int p)
{
  while(m[p]!=p)
    p=m[p];
  return p;
}
void combine(int t,int k)
{
  //k combine to t
  int t1=fint(t);
  int k1=fint(k);
  if(t1!=k1)
  {
    m[k1]=t1;
    ans--;
  }
}
int main()
{
   int N,M;
   while(scanf("%d",&N)&&N!=0)
   {
     ans=N-1;
     memset(m,0,sizeof(m));
     for(int i=1;i<=N;i++)
        m[i]=i;
     scanf("%d",&M);
     for(int i=0;i<M;i++)
     {
       int a,b;
       scanf("%d%d",&a,&b);
       combine(a,b);
     }
     printf("%d\n",ans);
   }
   return 0;
}
