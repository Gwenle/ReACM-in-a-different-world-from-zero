#include<iostream>
using namespace std;
typedef long long ll;
const ll vp=1000000001;
ll ksm(ll a,ll b)
{
  ll re=1;
  while(b!=0)
  {
    if(b&1)
     re=re*a;
    if(re>vp)
     re=re/10000000;
    a=a*a;
    if(a>vp)
     a=a/10000000;
    b=b>>1;
  }
  return re;
}//a^b
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
     ll p;
     cin>>p;
     ll ans=ksm(p,p);
     ll k=1;
     while(k<=ans)
      k*=10;
     k/=10;
     if(k==0)
      cout<<1<<endl;
     else
      cout<<ans/k<<endl;
   }
   return 0;
}
