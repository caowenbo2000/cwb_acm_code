#include<bits/stdc++.h>
using namespace std;
map<long long,int> mp;
int main()
{
    long long n,p,w,d;
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    long long x=-1,y=-1;
    for(long long i=0;i*d<=p;i++)//枚举i次平局
    {
        long long tmp=p-i*d;
        if(tmp%w==0)
        {
            y=i;
            x=tmp/w;
            break;
        }
        if(mp[tmp%w]==1)
        {
            break;
        }
        else
        {
            mp[tmp%w]=1;
        }
    }
    if(x!=-1&&x+y<=n)
    {
        printf("%lld %lld %lld\n",x,y,n-x-y);
    }
    else
    {
        printf("%d\n",-1);
    }
}
