#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int f[52][52];  //1000000010 is too big so i decide to change the status
int d[52];
//f[i][p]=min(f[i-1][p],f[i-1][p-1]-d[i]);
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      int n1,t;
      scanf("%d%d",&n1,&t);
      for(int j=0;j<n1;j++)
        scanf("%d",&d[j]);
      memset(f,-1,sizeof(f));
      f[0][0]=t;
      f[0][1]=t-d[0];
      for(int j=1;j<n1;j++)
        for(int k=0;k<j+2;k++)
        {
          if(k==j+1)
          {
            f[j][k]=f[j-1][k-1]-d[j];
            break;
          }
          f[j][k]=(k!=0&&f[j-1][k-1]-d[j]>0)? 
              min(f[j-1][k],f[j-1][k-1]-d[j]) : f[j-1][k];
        }
      int p,sum=0;
      for(p=0;p<=n1;p++)
        if(f[n1-1][p]<0)
          break;
      if(p!=0)
        sum=f[n1-1][p-1];
      printf("Case %d: %d %d\n",i,p,t-sum+678);
   }
   return 0;
}   
