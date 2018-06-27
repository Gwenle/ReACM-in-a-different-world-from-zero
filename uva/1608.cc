#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int lef[200010];
int righ[200010];
map<int,int> fg;
//first wrong is not find the mid 
inline bool ztxy(const int x,const int y)
{
    if(x>=y)
        return true;
    int x1=x,y1=y;
    //cout<<x1<<y1<<endl;
    while(x1<=y1)
    {
        if(lef[x1]<x&&(righ[x1]>y||righ[x1]==-1))
          return ztxy(x,x1-1)&&ztxy(x1+1,y);
        else
            x1++;
        if(lef[y1]<x&&(righ[y1]>y||righ[y1]==-1))
          return ztxy(x,y1-1)&&ztxy(y1+1,y);
        else
            y1--;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        fg.clear();
        int p;
        scanf("%d",&p);
        //memset(lef,-1,sizeof(lef));  就为了把这一个memsett优化掉卡了常数
        memset(righ,-1,sizeof(righ));
        for(int i=0;i<p;i++)
        {
            int a;
            scanf("%d",&a);
            map<int,int>::iterator it=fg.find(a);
            if(it!=fg.end())
            {
                int k=it->second;
                lef[i]=k;
                righ[k]=i;
            }
            else
            {
                lef[i]=-1;    
            }
            fg[a]=i;
            //it->second=i;
        }
        /*
        for(int i=0;i<p;i++)
        {
           cout<<"l-"<<lef[i]<<"r-"<<righ[i]<<" ";
        }
        */
        bool ans=ztxy(0,p-1);
        if(ans==true)
            printf("non-boring\n");
        else
            printf("boring\n");
    }
    return 0;
}
