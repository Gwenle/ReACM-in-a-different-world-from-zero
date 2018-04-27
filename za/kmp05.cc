#include<cstdio>
#include<cstring>
using namespace std;
char str[1010];
char stk[1010];
int next[1010];
int main()
{
  while(scanf("%s",str)&&str[0]!='#')
  {
    scanf("%s",stk);
    next[0]=-1;
    int len1=strlen(stk);
    for(int i=1,j=0;i<len1;i++)
    {
       while(j>0&&stk[j]!=stk[i])
          j=next[j];
       if(stk[j]==stk[i])
          j++;
       next[i+1]=j;
    }
    int len2=strlen(str);
    int i=0,j=0;
    int ans=0;
    while(i<len2)
    {
       if(str[i]==stk[j])
       {
         i++;
         j++;
       }
       else if(j==0)
       {
         i++;
       }
       else
         j=next[j]; 
       if(j==len1)
       {
         ans++;
         j=0;
       }
    }
    printf("%d\n",ans);
  }
  return 0;
}   
