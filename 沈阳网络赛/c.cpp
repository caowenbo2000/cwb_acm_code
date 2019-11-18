#include<bits/stdc++.h>
using namespace std;
int dp[100005][3];
vector<int>G[100005];
int typ[100005];
int vis[100005];
int n,m,k;
int dfs(int x)
{
    for(auto v: G[x])
    {
        if(typ[v]==1)
        {
            dp[v][1]=dp[x][0]+1;
        }
        else
        {
            dp[v][0]=max(dp[v][0],dp[x][0]+1);
            dp[v][1]=max(dp[v][1],dp[x][1]+1);
        }
        if(vis[v]==0)
        {
            vis[x]=1;
            dfs(v);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;i++)
        {
            int tmp1,tmp2;
            scanf("%d%d",&tmp1,&tmp2);
            G[tmp1].push_back(tmp2);
            G[tmp2].push_back(tmp1);
        }
        memset(typ,0,sizeof(typ));
        for(int i=1;i<=k;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            typ[tmp]=1;
        }
        dp[1][0]=1;
        dp[1][1]=1;
        vis[1]=1;
        dfs(1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(dp[i][0],ans);
            ans=max(dp[i][1],ans);
        }
        printf("%d\n",ans);
    }
}
