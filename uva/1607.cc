#include<iostream>
#include<cstring>
using namespace std;
typedef pair<int,int> pp;
int n,m;
pp f[1000100];
int g[1000100];//input
int t[2000200];//output
int test(int k)
{
  memset(g,0,sizeof(g));
  memset(t,0,sizeof(t));
  for(int i=1;i<=k;i++)
     g[i]=1;
  for(int j=0;j<m;j++)
  {
     int t1=f[j].first;
     int t2=f[j].second;
     if(t1<0)
      t[j]+=g[-t1];
     else
      t[j]+=(t[t1-1]==2)? 0 : 1;  
     if(t2<0)
      t[j]+=g[-t2];
     else
      t[j]+=(t[t2-1]==2)? 0 : 1;  
  }
  if(t[m-1]==2)
   return 0;
  else
   return 1; 
}
int main()
{
   std::ios::sync_with_stdio(false);
   int d;
   cin>>d;
   while(d--)
   {
     cin>>n>>m;
     for(int i=0;i<m;i++)
       cin>>f[i].first>>f[i].second;
     //cout<<test(0)<<" "<<test(n)<<endl;// test(0) and test(n) must opposite
     int beg=0,end=n;
     if(test(beg)==test(end))
     {
        for(int j=1;j<=n;j++)
          cout<<"0";
     }
     else
     {
     while((end-beg)>1)
     {
        int mid=(beg+end)/2;
        if(test(mid)==test(beg))
           beg=mid;
        else
           end=mid;
     }
     for(int j=1;j<=n;j++)
     {
        if(j<end)
         cout<<"1";
        else if(j==end)
         cout<<"x";
        else 
         cout<<"0";
     }
    }
     cout<<endl;
   }
   return 0;
}
