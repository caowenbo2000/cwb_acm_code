#include<bits/stdc++.h>
using namespace std;
set<int>G[100005],s;
int vis[100005];
queue<int>q;
void bfs(int x)
{
    q.push(x);
    while(q.size())
    {
        int tmp=q.front();
        q.pop();
        for(set<int>::iterator it=s.begin(); it!=s.end();)
        {
            int v=*it;
            it++;
            if(G[tmp].find(v)==G[tmp].end()&&vis[v]==0)
            {
                vis[v]=1;
                s.erase(v);
                q.push(v);
            }
        }
    }
    return ;
}
int main()
{
    memset(vis,0,sizeof(vis));
    int n,m;
    int cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) s.insert(i);
    for(int i=1; i<=m; i++)
    {
        int tmp1,tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        G[tmp1].insert(tmp2);
        G[tmp2].insert(tmp1);
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            bfs(i);
            cnt++;
        }
    }
    printf("%d\n",cnt-1);
}
