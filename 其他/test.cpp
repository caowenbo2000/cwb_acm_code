#include <iostream>
#include <queue>
#include<map>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

const int INF = 0x7fffffff;
int level[405];
int cnt=1;
int h;

struct Dinic
{
    int c;
    int f;
} edge[405][405];

bool dinic_bfs()      //bfs方法构造层次网络
{
    //cout<<"level"<<endl;
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(0);
    level[0] = 1;
    int u, v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (v = 1; v <= h; v++)
        {
            if (!level[v] && edge[u][v].c>edge[u][v].f)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[h] != 0;                //question: so it must let the sink node is the Mth?/the way of yj is give the sink node's id
}

int dinic_dfs(int u, int cp)             //use dfs to augment the flow
{
    int tmp = cp;
    int v, t;
    if (u == h)
        return cp;
    for (v = 1; v <= h&&tmp; v++)
    {
        if (level[u] + 1 == level[v])
        {
            if (edge[u][v].c>edge[u][v].f)
            {
                t = dinic_dfs(v, min(tmp, edge[u][v].c - edge[u][v].f));
                edge[u][v].f += t;
                edge[v][u].f -= t;
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
	memset(edge,0,sizeof(edge));
    int n,m,k;//1 源点 2 汇点
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        edge[0][i].c=3;
    }
    cin>>m;
    h=m+n+1;
    for(int i=1;i<=m;i++)
    {
        edge[n+i][h].c=3;//老师的容量
    }
    for(int i=1;i<=n;i++)
    {
        int tmp1,tmp2,tmp3;
        cin>>tmp1>>tmp2>>tmp3;
        edge[i][n+tmp1].c=1;
        edge[i][n+tmp2].c=1;
        edge[i][n+tmp3].c=1;
    }
    int ans;
    ans=dinic();
    cout<<ans<<endl;
    return 0;
}



/*
3
9
1 2 3
2 3 4
1 2 3
*/
