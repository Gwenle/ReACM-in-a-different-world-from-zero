#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
#include<fstream>
int s[100100];
char d[100100];
using namespace std;
//ofstream con("test");
inline double lk(int i,int j)
{
   double dk=(double)(s[j]-s[i])/(j-i);
   return dk;
}
int main()
{
   int n;
   scanf("%d",&n);
   int ans1,ans2;
   while(n--)
   {
     vector<int> op;
     memset(s,0,sizeof(s));
     memset(d,0,sizeof(d));
     int L,t;
     scanf("%d%d",&L,&t);
     scanf("%s",d);
     ans1=1;
     ans2=t;
     for(int i=1;i<=L;i++)
     {
       int j=d[i-1]-'0';
       s[i]=s[i-1]+j;
     }
     double mak=0;
     if(t+1<=L)
     {
      for(int i=t;i<=L;i++)
      {
        while(op.size()>1)
        {
          int last=*(op.end()-1);
          int next=*(op.end()-2);
          if(lk(last,i-t)<lk(next,last))
            op.pop_back();
          else
            break;
        }
        op.push_back(i-t);
        for(vector<int>::iterator j=op.begin();j!=op.end();j++)
        {
          if(lk(*j,i)>mak)
          {mak=lk(*j,i);ans1=*j+1;ans2=i;}
        }
      }
     }
    printf("%d %d\n",ans1,ans2);
   // con<<ans1<<" "<<ans2<<endl;
     /*
     for(int i=0;i<=L;i++)
       printf("%d",s[i]);
     printf("\n");
     */
     //i j averaeg s[j]-s[i-1]/(j-(i-1))
     
   }
   return 0;
}
