#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
//1000000010 is too big so i decide to change the status
int d[52];
typedef pair<int,int> pp;
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      vector<map<int,pp> > f;
      int n1,t;
      scanf("%d%d",&n1,&t);
      f.resize(n1+1);
      f[0][t]=pp(0,t);
      for(int j=0;j<n1;j++)
      {
        scanf("%d",&d[j]);
        for(map<int,pp>::iterator f1=f[j].begin();f1!=f[j].end();f1++)
        {
           int v=f1->first-d[j];
           if(v>0)
            f[j+1][v]=pp(0,v);
           int g=f1->first;
            f[j+1][g]=pp(0,g);
        }
      }
      for(int j=n1-1;j>=0;j--)
        for(map<int,pp>::iterator f1=f[j].begin();f1!=f[j].end();f1++)
      {
         int v1=f1->first,v2=f1->first-d[j];
         if(v2<=0)
         {  
           f1->second=f[j+1][v1];
           continue; 
         }
         int a1=f[j+1][v1].first;
         int b1=f[j+1][v1].second; 
         int a2=f[j+1][v2].first;
         int b2=f[j+1][v2].second;
         if(a1==a2+1)
         {
           f1->second=(b1<b2)?pp(a1,b1):pp(a1,b2);
         }
         else if(a1>a2+1)
           f1->second=pp(a1,b1);
         else
           f1->second=pp(a2+1,b2);
      }
      /*
      for(int j=0;j<n1+1;j++)
      {
        for(map<int,pp>::iterator f1=f[j].begin();f1!=f[j].end();f1++)
          cout<<f1->first<<"("<<f1->second.first<<","<<f1->second.second<<")"<<"\t";
        cout<<endl;
      }
      //print 
      */
      /*
      memset(f,-1,sizeof(f));
      f[0][0]=t;
      f[0][1]=t-d[0];
      for(int j=1;j<n1;j++)
        for(int k=0;k<j+2;k++)
        {
            int a=-1,b=-1;
            if(k!=0)
             a=f[j-1][k-1]-d[j];
            b=f[j-1][k];
            f[j][k]=max(a,b);
        }
       这是最开始因为背包容量上限太大改了状态方程
       这种状态可以极大的节省空间，f[i][j]表示前i个物品中挑选j个歌曲的剩余时间的最大值
       f[i][p]=max(f[i-1][p],f[i-1][p-1]-d[i]); 
       这样求出的p的值一定时最优的但是题目要求的是求出歌曲数最大时剩余时间的最小值
       然而如果用f[i][j]表示最小值则不具有递推关系无法DP
       然后我考虑了在知道p的值的情况下求出C N1 p的所有组合的值，然后二分找到最接近t的和
       然而在极端情况下如 C 50 25=126410606437752 储存这么大量的值这种解法已经非常不优美
       了并且对这么多的数只是一次快排就有可能超时所以这个解法被放弃了
       但是这个失败的思路被记录下来了，因为只是求P的值的话这种状态方程比j作为时间数组小
       太多，如果不是这个背包容量上限太大，我是无论如何都不会想到这么简介优美的DP，所以
       我觉得这种思路有被记录的必要
       https://zh.numberempire.com/combinatorialcalculator.php 这个组合数计算器真的好用
      int p=0;
      for(int j=0;j<=n1;j++)
        if(f[n1-1][j]>0)
             p=j;
      */
      printf("Case %d: %d %d\n",i,f[0][t].first+1,t-f[0][t].second+678);
   }
   return 0;
}   
