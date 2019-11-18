#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1000000;
int   a[1000005];//数字
int vis[1000005];//prime ?
vector<int> fac[1000005];// fac
vector<int> pos[1000005];// mei ge yin zi geshu
void intal()
{
    vis[1]=1;
    for(int i=2;i<=MAXN;i++)
    {
        if(vis[i]==1) continue;//素数作为因子
        fac[i].push_back(i);
        for(int j=2;j*i<=MAXN;j++)
        {
            vis[i*j]=1;
            fac[i*j].push_back(i);
        }
    }
    return ;
}
int main()
{
//    memset(fac,0,sizeof(fac));
//    memset(vis,0,sizeof(vis));
    intal();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(auto v: fac[a[i]])
        {
            pos[v].push_back(i);
        }
    }
    long long ans=0;
    for(int i=1;i<=MAXN;i++)
    {
        if(fac[i].size()==0) continue;
        ans+=1LL*n*(n+1)/2;
        int tmp=0;
        for(auto v:pos[i])
        {
            ans-=1LL*(v-tmp-1)*(v-tmp)/2;
            tmp=v;
        }
        ans-=1LL*(n-tmp+1)*(n-tmp)/2;
    }
    printf("%lld\n",ans);
}
