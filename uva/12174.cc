#include<iostream>
#include<cstring>
using namespace std;
int s,n;
int mv[100010];
bool str[200020];
int re[100010];
int rstr(int p)
{
  int f=p-s+1;
  if(p>0&&str[p-1]==true)
  {
     if(p>=n)
     {
       str[p]=true;
       return p+1;
     }
     int nw=mv[p];
     if(re[nw]==-1||re[nw]==f-1)
     {
        re[nw]=p;
        str[p]=true;
        return p+1;
     }
     else
     {
        return re[nw]+s;   
     }
  }
  for(int i=f;i<=p;i++)
  {  
     if(i<0)
      continue;
     if(i>=n)
      break;
     int now=mv[i];
     if(re[now]==-1||re[now]<f||re[now]==i)
     {
       re[now]=i; 
     }
     else
     {
       return re[now]+s;
     }
  }
  str[p]=true;
  return p+1; 
}
int main()
{
  std::ios::sync_with_stdio(false);
  int m;
  cin>>m;
  while(m--)
  {
     int ans=0;
     cin>>s>>n;
     for(int i=0;i<n;i++)
       cin>>mv[i];
     memset(str,0,sizeof(str));
     memset(re,-1,sizeof(re));
     for(int j=0;j<n+s-1;)
     {
       j=rstr(j);
     }
     for(int i=0;i<s;i++)
     {
       bool bi=true;
       int k=i;
       while(k<n+s-1)
       {
         if(str[k]==false)
         {
            bi=false;
            break;
         }
         k=k+s;
       }
       if(bi==true)
         ans++;
     }
    /*
     for(int i=0;i<n+s-1;i++)
      cout<<str[i];
     cout<<endl;
    */
     cout<<ans<<endl;
   }
   return 0;
}
         
