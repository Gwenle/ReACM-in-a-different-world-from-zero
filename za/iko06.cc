#include<cstdio>
#include<cstring>
int re[50010];
int fint(int m)
{
  if(m!=re[m])
   m=fint(re[m]);
  return m;  
}
void combine(int a,int b,int& t)
{
   int a1=fint(a);
   int b1=fint(b);
   if(a1!=b1)
   {
     re[a1]=b1;
     t--;
   }
}   
int main()
{
  int n,m,cas=0;
  while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
  {
    cas++;
    for(int i=1;i<=n;i++)
      re[i]=i;
    for(int i=1;i<=m;i++)
    {
      int j,k;
      scanf("%d%d",&j,&k);
      combine(j,k,n);
    }
    printf("Case %d: %d\n",cas,n);
  }
  return 0;
}
