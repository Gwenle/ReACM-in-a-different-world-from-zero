#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  string s;
  map<string,string> smap;//key
  while(getline(cin,s)&&s!="@END@")
  {
    //Memory Limit Exceeded so I try only one map
    //map<string,string> maps;value
    istringstream con(s);
    string s1,s2;
    con>>s1;
    con.ignore();
    getline(con,s2);
    smap[s1]=s2;
   /*
    s1.erase(s1.begin());
    s1.erase(--s1.end());
    maps[s2]=s1;
   */
  } 
  int n;
  cin>>n;
  cin.ignore();
  string t;
  while(n--)
  {
    getline(cin,t);
   //map<string,string>& tmap=(t[0]=='[')? smap : maps;
   /*
    if(tmap.find(t)==tmap.end())
     cout<<"what?"<<endl;
    else
     cout<<tmap.find(t)->second<<endl;
   */
   if(t[0]=='[')
   {
     if(smap.find(t)==smap.end())
     cout<<"what?"<<endl;
    else
     cout<<smap.find(t)->second<<endl;
   }
   else 
   {
     map<string,string>::iterator i;
     for(i=smap.begin();i!=smap.end();i++)
       if(i->second==t)
          break;
     if(i!=smap.end())
     {
       const string& sp=i->first;
       for(int j=1;j<sp.size()-1;j++)
        cout<<sp[j];
       cout<<endl;
     }
     else
      cout<<"what?"<<endl;
   }
  }
  return 0;
}
