#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int A[200100];
int g[200100];
int f[200100];
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
     int k;
     memset(A,0,sizeof(A));
     memset(g,0,sizeof(g));
     memset(f,0,sizeof(f));
     scanf("%d",&k);
     for(int i=0;i<k;i++)
       scanf("%d",&A[i]);
     g[0]=1;
     for(int i=1;i<k;i++)
     {
       if(A[i]>A[i-1])
        g[i]=g[i-1]+1;
       else
        g[i]=1;
     }
     f[k-1]=1;
     for(int i=k-2;i>=0;i--)
     {
       if(A[i]<A[i+1])
         f[i]=f[i+1]+1;
       else
         f[i]=1;
     }
     int ans=0;
      
     //laji n^2 xiefa TLE
     /*
     for(int i=0;i<k-1;i++)
      for(int j=i+1;j<k;j++)
      { 
        if(A[j]>A[i])
         ans=max(ans,g[i]+f[j]);
      }
     */
     printf("%d\n",ans);
   }
   return 0;
}
