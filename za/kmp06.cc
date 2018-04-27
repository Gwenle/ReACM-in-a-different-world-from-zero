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
     re=((re%vp)*(a%vp))%vp;
    a=((a%vp)*(a%vp))%vp;
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
     int k=1;
     while(k<=ans)
      k*=10;
     k/=10;
     cout<<ans/k<<endl;
   }
   return 0;
}
