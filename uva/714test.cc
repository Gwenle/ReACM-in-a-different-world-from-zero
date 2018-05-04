#include<iostream>
#include<string>
#include<sstream>
#include<set>
using namespace std;
typedef long long ll;
int main()
{
   set<ll> sp;
   string s;
   ll sum=0;
   while(cin>>s)
   {
     if(s[0]!='/')
     {
       stringstream con(s);
       ll p;
       con>>p;
       //cout<<p<<endl;
       sum+=p;
     }
     else
     {
       sp.insert(sum);
       sum=0;
     }
   }
   sp.insert(sum);
   cout<<*sp.rbegin()<<endl;
   return 0;
}
