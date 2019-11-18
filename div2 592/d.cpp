#include<bits/stdc++.h>
using namespace std;
vector<int>G[100005];
int vis[100005];
int num[100005];
int col[100005];
long long dp[100005];
int c[4][100005];
int first;
void dfs(int x,int dep)
{
    vis[x]=1;
    num[dep]=x;
    for(auto v:G[x])
    {
        if(vis[v]) continue;
        dfs(v,dep+1);
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        int tmp1,tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
    }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
         if(G[i].size()>=3)
         {
             flag=1;
         }
         if(G[i].size()==1)
         {
             first=i;
         }
    }
    if(flag==1)//不是一条链
    {
        printf("-1\n");
        return 0;
    }
    dfs(first,1);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<i<<":"<<num[i]<<endl;
//    }
    long long ans=1e18;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i==j) continue;
            col[num[1]]=i;
            dp[1]=c[i][num[1]];
            col[num[2]]=j;
            dp[2]=dp[1]+c[j][num[2]];
            for(int k=3;k<=n;k++)
            {
                col[num[k]]=6-col[num[k-1]]-col[num[k-2]];
                dp[k]=dp[k-1]+c[col[num[k]]][num[k]];
            }
            ans=min(ans,dp[n]);
        }
    }
    flag=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i==j) continue;
            col[num[1]]=i;
            dp[1]=c[i][num[1]];
            col[num[2]]=j;
            dp[2]=dp[1]+c[j][num[2]];
            for(int k=3;k<=n;k++)
            {
                col[num[k]]=6-col[num[k-1]]-col[num[k-2]];
                dp[k]=dp[k-1]+c[col[num[k]]][num[k]];
            }
            if(ans==dp[n])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
    {
        printf("%d%s",col[i],i==n?"\n":" ");
    }
    return 0;
}
