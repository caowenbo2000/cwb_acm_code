#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
vector<int> G[300005];
int vis[300005];
int num[300005];
long long sum=0;
long long ans=1;
long long quick_power(long long x)
{
    long long ans1=1;
    long long a=2;
    while(x)
    {
        if(x&1)
        {
            ans1=(ans1*a)%mod;
        }
        a=(a*a)%mod;
        x/=2;
    }
    return ans1;
}
void dfs(int x,int father)
{
    vis[x]=1;
    for(auto v:G[x])
    {
         if(father==v) continue;
         if(vis[v]==1)
         {
             if(num[x]-num[v]>0)
             {
             ans=(ans*(quick_power(num[x]-num[v]+1)+mod-1))%mod;
             //cout<<x<<" "<<v<<endl;
             sum+=num[x]-num[v]+1;
             }
         }
         else
         {
             vis[v]=1;
             num[v]=num[x]+1;
             dfs(v,x);
         }
    }
    return ;
}
int main()
{
    int t;
    t=1;
    while(t--)
    {
        sum=0;
        ans=1;
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int tmp1,tmp2;
            scanf("%d%d",&tmp1,&tmp2);
            G[tmp1].push_back(tmp2);
            G[tmp2].push_back(tmp1);
        }
        //cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0) dfs(i,0),num[i]=1;
        }
        //cout<<sum<<endl;
        if(m!=sum)
        ans=ans*quick_power(m-sum)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
