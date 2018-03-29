#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
typedef map<char,int> ma;
int main()
{
  string s;
  while(cin>>s)
 {
  ma m;
  for(string::iterator i=s.begin();i!=s.end();i++)
  {
     m[*i]++;
  }
  for(ma::iterator i=m.begin();i!=m.end();i++)
  {
     cout<<i->first<<":"<<i->second<<endl;
  }
 }
  return 0;
}
