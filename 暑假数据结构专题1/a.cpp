#define LOCAL
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int IN[205];
int OUT[205];

//0 源点 cnt+1汇点
const int INF = 0x7fffffff;
int level[405];
int cnt=1;
int m;
 
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
        for (v = 1; v <= cnt+1; v++)
        {
            if (!level[v] && edge[u][v].c>edge[u][v].f)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[cnt+1] != 0;                //question: so it must let the sink node is the Mth?/the way of yj is give the sink node's id
}
 
int dinic_dfs(int u, int cp)             //use dfs to augment the flow
{
    int tmp = cp;
    int v, t;
    if (u == cnt+1)
        return cp;
    for (v = 1; v <= cnt+1&&tmp; v++)
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
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    #endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(edge,0,sizeof(edge));
        memset(IN,0,sizeof(IN));
        memset(OUT,0,sizeof(OUT));
        scanf("%d%d",&cnt,&m);
        for(int i=1;i<=m;i++)
        {
            int tmp1,tmp2,tmp3;
            scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
            IN[tmp2]++;
            OUT[tmp1]++;
            if(tmp3==0)
            {
                edge[tmp1][tmp2].c+=1;
            }
        }
        int flag=0;
        int num=0;
        for(int i=1;i<=cnt;i++)
        {
            if(abs(IN[i]-OUT[i])%2==1)
            {
                flag=-1;
                break;
            }
            else 
            {
                if(IN[i]>OUT[i])
                {
                    edge[i][cnt+1].c+=(IN[i]-OUT[i])/2;
                }
                if(IN[i]<OUT[i])
                {
                    edge[0][i].c+=(OUT[i]-IN[i])/2;
                    num+=(OUT[i]-IN[i])/2;
                }
            }
        }
        if(flag==0&&dinic()==num)
        {
            printf("possible\n");
        }
        else 
        {
            printf("impossible\n");
        }
    }
    return 0;
}
