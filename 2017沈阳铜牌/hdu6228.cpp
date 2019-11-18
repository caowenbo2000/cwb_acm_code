#include<bits/stdc++.h>
using namespace std;
vector<int>G[200005];
map<int,bool>vis;
int n;
int k;
int cnt=0;
int dfs(int x)
{
    int si=1;
    vis[x]=1;
    for(auto v:G[x])
    {
        if(vis[v]==0)
        {
            int num=dfs(v);
            si+=num;
            if(num>=k&&n-num>=k)
            {
                cnt++;
            }
        }
    }
    return si;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        vis.clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++)
        {
            int tmp1,tmp2;
            scanf("%d%d",&tmp1,&tmp2);
            G[tmp1].push_back(tmp2);
            G[tmp2].push_back(tmp1);
        }
        dfs(1);
        printf("%d\n",cnt);
    }
}
