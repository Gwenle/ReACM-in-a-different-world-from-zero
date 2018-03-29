#include<cstdio>
#include<utility>
using namespace std;
int m[1000];
inline pair<int,int> vod(int n)
{
  int i=1,ans=1,p;
  while(ans<=n)
  {
    p=ans;
    i=i+2;
    ans+=2*i;
  }
  return pair<int,int>(i-2,p);
}
int main()
{
  int n,j;
  char d;
  scanf("%d",&n);
  getchar();
  scanf("%c",&d);
  pair<int,int> c=vod(n);
  int i=c.first;
  for(j=i;j>=1;j=j-2)
  {
    int p1=(i-j)/2,p2=j;
    while(p1--)
     printf(" ");
    while(p2--)
     printf("%c",d);
    printf("\n");
  }
  for(j+=4;j<=i;j=j+2)
  {
    int p1=(i-j)/2,p2=j;
    while(p1--)
     printf(" ");
    while(p2--)
     printf("%c",d);
    printf("\n");
  }
  printf("%d\n",n-c.second);
  return 0;
} 
