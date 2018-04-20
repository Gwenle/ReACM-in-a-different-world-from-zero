#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int re[50010];
map<int,int> eat;
map<int,int> food;
int fint(int m)
{
   if(m>0&&re[m]!=m)
     m=fint(re[m]);
   return m;
}
bool combine(int a,int b)
{
   int a1=fint(a);
   int b1=fint(b);
   if(a1==b1)
     return true;
   if(a1<0&&b1<0)
     return false;
   if(a1<0&&b1>0)
     swap(a1,b1);
   re[a1]=b1;
   return true;
}
int main()
{
   int ans=0,pk=0;
   int N,K;
   cin>>N>>K;
   for(int i=1;i<=N;i++)
    re[i]=i;
   while(K--)
   {
     int D,X,Y;
     cin>>D>>X>>Y;
     if(X>N||Y>N)
     {
       ans++;
       continue;
     }
     if(D==1)
     {
       bool ve=combine(X,Y);
       if(ve==false)
         ans++;
     }
     if(D==2)
     {
       if(X==Y)
       { ans++; continue;} 
       int x1=fint(X);
       int y1=fint(Y);
       if(x1<0&&y1<0)
       {
         int t1=x1+1;
         if(t1==0)
          t1=-3;
         if(t1!=y1)
          ans++;
         continue; 
       }
         map<int,int>::iterator i1=eat.find(x1);
         map<int,int>::iterator i2=food.find(y1);
         map<int,int>::iterator i3=eat.find(y1);
       if(x1>0&&y1>0)
       {
         if(pk==0)
         {
          re[x1]=-1;
          re[y1]=-2;
          pk++;
          continue;
         }
         if(i3!=eat.end()&&(i3->second)==x1)
         {
            ans++;
            continue;
         }
         if(i1==eat.end()&&i2==food.end())
         {
           eat[x1]=y1;
           food[y1]=x1;
           continue;
         }
         if(i1!=eat.end())
           combine(Y,eat[x1]);
         if(i2!=food.end())
           combine(X,food[y1]); 
         continue;
       }
       if(x1<0)
       {
         int t1=x1+1;
         if(t1==0)
          t1=-3;
         re[y1]=t1;
         continue;
       }
       if(y1<0)
       {
         int t1=y1-1;
         if(t1==-4)
           t1=-1;
         re[x1]=t1;
         continue;
       }
     }
   }
   printf("%d\n",ans);
   return 0;
}      
