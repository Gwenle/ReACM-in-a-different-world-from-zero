#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
int m[20010];
int mb[20010];
//maybe oj limit map
typedef map<int,int> mk;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    memset(m,0,sizeof(m));
    memset(mb,-1,sizeof(mb));
    // map<int,int> mb;//2 405
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&m[i]);
    mb[1]=m[n-1];
    int ok=1;
  /*  for(int i=n-2;i>=0;i--)
    {
      for(mk::reverse_iterator j=mb.rbegin();j!=mb.rend();j++)
      {
        if(m[i]>=(j->second))
        {
           int a=j->first+1;
           if(mb.find(a)==mb.end()||mb[a]>m[i])
           {
              mb[a]=m[i];
           }
           break;
        }
      }
    }  map */
    for(int i=n-2;i>=0;i--)
    {
      for(int j=ok;j>=1;j--)
      {
        if(m[i]>=mb[j])
        {
           if(mb[j+1]==-1||mb[j+1]>m[i])
              mb[j+1]=m[i];
           if(j+1>ok)
              ok=j+1;
           break;
        }
      }
    }
    printf("%d\n",n-ok);
   }
   return 0;
}
