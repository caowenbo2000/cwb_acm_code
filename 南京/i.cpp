#include <iostream>
#include <queue>
#include<map>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

const int INF = 0x7fffffff;
int level[2005];
int cnt=-1;
int n,m,k;
struct Dinic
{
    int to;
    int c;
    int f;
} edge[500005];
int first[2005];
int nxt[500005];

void add(int u,int v,int num)
{
    ++cnt;
    nxt[cnt]=first[u];
    first[u]=cnt;
    edge[cnt].to=v;
    edge[cnt].c=num;
    edge[cnt].f=0;
    ++cnt;
    nxt[cnt]=first[v];
    first[v]=cnt;
    edge[cnt].to=u;
    edge[cnt].c=0;
    edge[cnt].f=0;
}

bool dinic_bfs()      //bfs方法构造层次网络
{
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(0);
    level[0] = 1;
    int u, v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if(u==n+m+2) return 1;
        for (int i = first[u]; i!=-1 ; i=nxt[i])
        {
            v=edge[i].to;
            if (!level[v] && edge[i].c>edge[i].f)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[n+m+2] != 0;                //question: so it must let the sink node is the Mth?/the way of yj is give the sink node's id
}

int dinic_dfs(int u, int cp)             //use dfs to augment the flow
{
    int tmp = cp;
    int v, t;
    if (u == n+m+2)
        return cp;
    for (int i=first[u]; i!=-1&&tmp; i=nxt[i])
    {
        v=edge[i].to;
        if (level[u] + 1 == level[v])
        {
            if (edge[i].c>edge[i].f)
            {
                t = dinic_dfs(v, min(tmp, edge[i].c - edge[i].f));
                edge[i].f += t;
                edge[i^1].f -= t;
                tmp -= t;
            }
        }
    }
    return cp - tmp;
}

int dinic()
{
    int sum=0, tf=0;
    while (dinic_bfs())
    {
        while (tf = dinic_dfs(0, INF))
            sum += tf;
    }
    return sum;
}

int main()
{
    memset(first,-1,sizeof(first));
    scanf("%d%d%d",&n,&m,&k);//0源点 1~n英雄  n+1~n+m怪物 n+m+1药水  n+m+2汇点
    add(0,n+m+1,k);
    for(int i=1; i<=n; i++)
    {
        add(0,i,1);
        add(n+m+1,i,1);
    }
    for(int i=1; i<=m; i++)
    {
        add(n+i,n+m+2,1);
    }
    for(int i=1; i<=n; i++)
    {
        int tmp;
        int temp;
        scanf("%d",&tmp);
        for(int j=1; j<=tmp; j++)
        {
            scanf("%d",&temp);
            add(i,n+temp,1);
        }
    }
    printf("%d\n",dinic());
    return 0;
}
