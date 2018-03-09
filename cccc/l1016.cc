#include<cstdio>
#include<cstring>
using namespace std;
char w[104][19];
char a[12]={'1','0','X','9','8','7','6','5','4','3','2'};
int  b[18]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,
           4,2};
int main()
{
  int n;
  while(scanf("%d",&n)==1)
  {
    memset(w,0,sizeof(w));
    for(int i=0;i<n;i++)
      scanf("%s",w[i]); 
    bool t=false;
    for(int i=0;i<n;i++)
    {
      int ans=0;
      for(int j=0;j<17;j++)
      {
         ans+=(w[i][j]-'0')*b[j];
      }
      ans=ans%11;
      if(a[ans]!=w[i][17])
      {
        t=true;
        printf("%s\n",w[i]);
      }
    }
    if(!t)
     printf("All passed\n");
  }
  return 0;
}
