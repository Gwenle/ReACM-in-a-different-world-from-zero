#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<deque>
#include<fstream>
int s[100100];
char d[100100];
using namespace std;
//ofstream con("test");
/*inline double lk(int i,int j)
{
   double dk=(double)(s[j]-s[i])/(j-i);
   return dk;
}*/ 
int combine(const int x1,const int y1,const int x2,const int y2)
{
   return (s[y1]-s[x1])*(y2-x2)-(s[y2]-s[x2])*(y1-x1);
} 
int main()
{
   int n;
   scanf("%d",&n);
   int ans1,ans2;
   while(n--)
   {
     deque<int> op;
     memset(s,0,sizeof(s));
     memset(d,0,sizeof(d));
     int L,t;
     scanf("%d%d",&L,&t);
     scanf("%s",d);
     ans1=1;
     ans2=L;
     for(int i=1;i<=L;i++)
     {
       int j=d[i-1]-'0';
       s[i]=s[i-1]+j;
     }
      for(int i=t;i<=L;i++)
      {
        while(op.size()>1)
        {
          int last=*(op.end()-1);
          int next=*(op.end()-2);
          if(combine(next,last,last,i-t)>0)
            op.pop_back();
          else
            break;
        }
        op.push_back(i-t);
        while(op.size()>1)
        {
          int last=*op.begin();
          int next=*(op.begin()+1);
          //if(lk(last,i-t)<lk(next,last))
          if(combine(last,i,next,i)<=0)// <= !! not <
            op.pop_front();
          else
            break;
        }
        int v=combine(op[0],i,ans1-1,ans2);
        if(v>0||(v==0&&(ans2-ans1+1>i-op[0])))
        {
          ans1=op[0]+1;
          ans2=i;
        }
      } 
    printf("%d %d\n",ans1,ans2);
    //con<<ans1<<" "<<ans2<<endl;
     /*
     for(int i=0;i<=L;i++)
       printf("%d",s[i]);
     printf("\n");
     */
     //i j averaeg s[j]-s[i-1]/(j-(i-1))
     
   }
   return 0;
}


//!!!
