//https://www.nowcoder.com/acm/contest/121/I
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
   int n,ans=0;
   cin>>n;
   vector<int> p;
   for(int i=0;i<n;i++)
   {
     int k;
     cin>>k;
     p.push_back(k);
   }
   vector<int> m=p;
   sort(m.begin(),m.end());
   auto q=m.rbegin();
   for(auto g=p.rbegin();g!=p.rend();g++)
   {
      if(q==m.rend())
         break;
      if(*g==*q)
      {
        ans++;
        q++;
      }
   }
   cout<<n-ans<<endl;
   return 0;
}
