#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
int m[2400];
int main()
{
  int N,K;
  int v;
  scanf("%d",&v);
  while(v--)
  {
   set<int> op;
   scanf("%d%d",&N,&K);
   for(int i=0;i<N;i++)
     scanf("%d",m+i);
   for(int i=0;i<N-1;i++)
     for(int j=i+1;j<N;j++)
      op.insert(abs(m[i]-m[j]));
   set<int>::iterator f=op.begin();
   while(--K)
     f++;
   printf("%d\n",*f);  
  }
  return 0;
} 
      
