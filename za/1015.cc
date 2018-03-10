#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
int m[20010];
typedef map<int,int> mk;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    memset(m,0,sizeof(T));
    map<int,int> mb;//2 405
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&m[i]);
    mb[1]=m[n-1];
    for(int i=n-2;i>=0;i--)
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
    }
    printf("%d\n",n-mb.rbegin()->first);
   }
   return 0;
}
