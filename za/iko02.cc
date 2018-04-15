#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int m[2400];
int n[2400];
int main()
{
  int N,K;
  int v;
  scanf("%d",&v);
  while(v--)
  {
   memset(n,0,sizeof(n));
   scanf("%d%d",&N,&K);
   for(int i=0;i<N;i++)
     scanf("%d",m+i);
   for(int i=0;i<N-1;i++)
     for(int j=i+1;j<N;j++)
     {
        int op=abs(m[i]-m[j]);
        n[op]++;
     }
   int t;
   for(t=0;t<=2000;t++)
   {
      if(n[t]!=0)
       K--;
      if(K==0)
       break;
   }
   printf("%d\n",t);
  }
  return 0;
} 
      
