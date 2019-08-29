//树上差分
#include<bits/stdc++.h>
using namespace  std;
int v[10005];
int u[10005];
vector<int>G[10005];
int vis[10005];
int dep[10005];
int num1[10005];
int num2[10005];
int sum1=0;
int sum2=0;
int ans[10005];
int dfs(int x,int father)
{
    vis[x]=1;
    for(auto V:G[x])
    {
        if(V==father) continue;
        if(vis[V]==0)
        {
           // cout<<":1"<<x<<" "<<V<<endl;
            dep[V]=dep[x]+1;
            dfs(V,x);
        }
        else if(vis[V]==1&&dep[V]<dep[x])
        {  // cout<<":2"<<x<<" "<<V<<endl;
            int len=dep[x]-dep[V]+1;
            if(len%2==1)
            {
                num1[x]+=1;
                num1[V]-=1;
                sum1++;
            }
            else
            {
                num2[x]++;
                num2[V]--;
                sum2++;
            }
        }
    }
}
int dfs_sum(int x,int father)
{
    vis[x]=1;
    for(auto V:G[x])
    {
        if(V==father) continue;
        if(vis[V]==0)
        {
            dfs_sum(V,x);
            num1[x]+=num1[V];
            num2[x]+=num2[V];
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++) //建立差分数组
    {
        if(vis[i]==0) dfs(i,0);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        dfs_sum(i,0);
    }
    int cnt=0;
    for(int i=1; i<=m; i++)
    {
        if(dep[u[i]]<dep[v[i]]) swap(u[i],v[i]);
        if(sum1==0||dep[u[i]]!=dep[v[i]]+1&&sum1==1&&(dep[u[i]]-dep[v[i]]+1)%2==1||dep[v[i]]+1==dep[u[i]]&&num1[u[i]]==sum1&&num2[u[i]]==0)
        {
            cnt++;
            ans[cnt]=i;
        }
    }
    printf("%d\n",cnt);
    for(int i=1; i<=cnt; i++)
    {
        printf("%d%s",ans[i],i==cnt?"\n":" ");
    }
}
