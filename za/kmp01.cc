#include<cstdio>
#include<cstring>
using namespace std;
int next[10010];
char stk[10010];
char str[1000100];
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    int ans=0;
    scanf("%s",stk);
    scanf("%s",str);
    memset(next,0,sizeof(next));
    next[0]=-1;
    int l1=strlen(stk);
    //next function
    for(int i=1,j=0;i<l1-1;i++)
    {
      while(j>0&&stk[j]!=stk[i])
         j=next[j-1];
      j++;  
      next[i]=j;
    }
    printf("%s\n",stk);
    for(int i=0;i<l1;i++)
     printf("%d ",next[i]);
    printf("\n");  
  }
  return 0;
}
