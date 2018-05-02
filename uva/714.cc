#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
int m[550];
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
     stack<int> z;
     int a,b,sum=0;
     scanf("%d%d",&a,&b);
     for(int i=0;i<a;i++)
     {
       scanf("%d",&m[i]);
       sum+=m[i];
     }
     double avg=(double)sum/b;
     int kt=0,kf=0,p=b-1;
     for(int i=0;i<a;i++)
     {
       kt=kt+m[i];
       if(p>0&&kt>avg)
       {
          p--;
          if(i==0)
          {
            kf=kt;
            kt=0;
            continue;
          }
          double i1=fabs(kt-avg);
          double i2=fabs(kt-m[i]-avg);
          if(i1<=i2)
          {
            kf=max(kt,kf);
            kt=0;
          }
          else
          {
            kf=max(kf,kt-m[i]);
            kt=m[i];
          }
       }
     }
     kf=max(kf,kt);//maximum number of pages assigned to a single scriber
     //printf("%d\n",kf);
     p=b-1;
     int vx=m[a-1];
     int j=a-2;
     while(j>=0&&p>0)
     {
       vx+=m[j];
       if(p-1==j||vx>kf)
       {
         z.push(j);
         p--;
         vx=m[j];
       }
       j--;
     }
     int t1=z.top();
     z.pop();
     for(int i=0;i<a;i++)
     {
       if(i!=0)
        printf(" ");
       printf("%d",m[i]);
       if(i==t1)
       {
         printf(" /");
         if(!z.empty())
         {
           t1=z.top();
           z.pop();
         }
       }
     }
     printf("\n");  
  }
  return 0;
}


/* 
test1 :
6 3
1 3 5 2 5 2
*/
