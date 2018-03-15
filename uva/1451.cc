#include<cstdio>
#include<algorithm>
#include<cstring>
int s[100100];
char d[100100];
using namespace std;
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
     memset(s,0,sizeof(0));
     memset(d,0,sizeof(0));
     int L,t;
     scanf("%d%d",&L,&t);
     scanf("%s",d);
     for(int i=1;i<=L;i++)
     {
       int j=d[i-1]-'0';
       s[i]=s[i-1]+j;
     }
     /*
     for(int i=0;i<=L;i++)
       printf("%d",s[i]);
     printf("\n");
     */
     //i j averaeg s[j]-s[i-1]/(j-(i-1))
     double dk=(double)(s[11]-s[6])/(11-6);
   }
   return 0;
}
