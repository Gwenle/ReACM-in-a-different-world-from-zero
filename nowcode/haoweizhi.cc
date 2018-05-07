//https://www.nowcoder.com/acm/contest/109/B

#include<iostream>
#include<string>
#include<map>
using namespace std;
bool cmp(const string& s,const string& x)
{
    if(x.size()>s.size())
      return false;
    map<char,int> m;
    m[x[x.size()-1]]=x.size()-1;
    int j=x.size()-1;
    int t=j;//map border
    for(int i=s.size()-1;i>=0;i--)
    {
       int f;
       if(m.find(s[i])==m.end())
         return false;
       else
         f=m[s[i]];
       if(s[i]==x[j]&&j>=0)
          j--;
       else if(j<f)
          j=f-1;
       else
          return false;    
       if(f==t&&t>0)
       {
         m[x[t-1]]=t-1;
         t--;
       }
    }
    if(j==-1)
      return true;
    else
      return false;
}
int main()
{
   std::ios::sync_with_stdio(false);
   string s,x;
   cin>>s>>x;
   if(cmp(s,x))
    cout<<"Yes"<<endl;
   else 
    cout<<"No"<<endl;
   return 0;
}
