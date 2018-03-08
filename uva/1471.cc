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
     map<int,int> ma;     
     ma[A[0]]=g[0];
     for(int i=1;i<k;i++)
     {
      if(A[i]>(ma.begin()->first))
      {
        auto a1=ma.lower_bound(A[i]);
        a1--;
        int b1=a1->second;
        ans=max(ans,b1+f[i]);
        // A[i],g[i] 
        auto a2=ma.upper_bound(A[i]);
        a2--;
        if(g[i]>(a2->second))
        {
          if((a2->first)==A[i])
            a2=ma.erase(a2);
          else
            a2++;
          for(auto ap=a2;ap!=ma.end();)
          {
            if((ap->second)<=g[i])
              ap=ma.erase(ap);
            else 
              break;//!!
          }
          ma[A[i]]=g[i];
        }
      }
      else
      {
       for(auto ap=ma.begin();ap!=ma.end();)
       {
            if((ap->second)<=g[i])
              ap=ma.erase(ap);
            else 
              break;//!!
       }
       if(ma.find(A[i])==ma.end())
       {
           ma[A[i]]=g[i];
       }
      }
     }   
     printf("%d\n",ans);
   }
   return 0;
}
