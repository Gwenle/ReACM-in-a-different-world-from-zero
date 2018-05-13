#include<cstdio>
using namespace std;
int m[100010];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
     int t;
     scanf("%d",&t);
     for(int j=0;j<t;j++)
       scanf("%d",&m[j]);
     for(int j=0;j<t;j++)
     {
       int p;
       scanf("%d",&p);
       m[j]-=p;
     }
     int k=0;//begin
     bool ans=false;
     while(k<t)
     {
        int sum=0,v=k;
        for(int o=0;o<t;o++,v++)
        {
           if(v==t)
             v=0;
           sum+=m[v];
           if(sum<0)
           {
             v++;
             break;
           }
           if(o==t-1)
             ans=true;
        }
        //printf("%d\n",k);
        if(ans==true)
          break;
        else if(v>k)
          k=v;
        else 
          break;
     }
     printf("Case %d: ",i);
     if(ans==false)
       printf("Not possible\n");
     else
       printf("Possible from station %d\n",k+1);
  }
  return 0;
}
