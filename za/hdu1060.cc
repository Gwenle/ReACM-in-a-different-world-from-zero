#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
int main()
{
   int p;
   cin>>p;
   while(p--)
   {
     ll t;
     cin>>t;
     double k=t*log10(t*1.0);
     k=k-(ll)k;
     ll v=(ll)pow(10.0,k);
     cout<<v<<endl;
   } 
   return 0;
}
