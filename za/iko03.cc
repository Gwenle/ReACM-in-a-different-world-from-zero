#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int p[3100];
int k[10000];
int main()
{
  int n,m;
  ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    int oj=0;
    memset(k,0,sizeof(k));
    for(int i=0;i<n;i++)
     cin>>p[i];
    int max1=0;
    for(int i=0;i<n-1;i++)
     for(int j=i+1;j<n;j++)
    {
      k[p[j]+p[i]]++;
      max1=max(p[j]+p[i],max1);
    }
    for(int p=max1;p>0;p--)
    {
      while(k[p]>0&&m>0)
      {
        if(oj!=0)
         cout<<" ";
        oj++;
        cout<<p;
        k[p]--;
        m--;
      }
      if(m<=0)
        break;
     }
     cout<<endl;
   }
   return 0;
}
