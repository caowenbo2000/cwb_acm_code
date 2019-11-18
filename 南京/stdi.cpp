#include <iostream>
#include <queue>
#include<map>
#include<cstring>
#include<cstdio>
#define MEET n+m+2
using namespace std;

const int INF = 1e9+100;
int level[1005];
int  cnt=-1;
int n,m,k;

int first[1005];//0 Դ�� 1-2n ţ 2n+d food 2n+d+p drink
int nxt[300005];
int to[300005];
int c[300005];
int f[300005];

bool dinic_bfs()      //bfs��������������
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
        if(u==MEET) return true;
        for (int i = first[u]; i != -1; i=nxt[i])
        {
            v=to[i];
            if (!level[v] && c[i]>f[i])
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
   return false;               //question: so it must let the sink node is the Mth?/the way of yj is give the sink node's id
}

int dinic_dfs(int u, int cp)             //use dfs to augment the flow
{
    //cout<<"cp"<<cp<<endl;
    int tmp = cp;
    int v, t;
    if (u == MEET)
        return cp;
    for (int i=first[u]; i!=-1&&tmp; i=nxt[i])
    {
        //cout<<"i3"<<i<<endl;
        v=to[i];
        if (level[u] + 1 == level[v])
        {
            if (c[i]>f[i])
            {
                t = dinic_dfs(v, min(tmp,c[i] - f[i]));
                f[i] += t;
                f[i^1] -= t;
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

void add(int st,int  en,int num)
{
    cnt++;
    nxt[cnt]=first[st];
    first[st]=cnt;
    to[cnt]=en;
    c[cnt]=num;
    f[cnt]=0;

    cnt++;
    nxt[cnt]=first[en];
    first[en]=cnt;
    to[cnt]=st;
    c[cnt]=0;
    f[cnt]=0;
}

int main()//0Ϊ��� 2n+1Ϊ�յ� ����Ϊ�ߵ���� ż��Ϊ�ߵ��յ�
{
    memset(first,-1,sizeof(first));
    scanf("%d%d%d",&n,&m,&k);//0Դ�� 1~nӢ��  n+1~n+m���� n+m+1ҩˮ  n+m+2���
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
    int ans;
    ans=dinic();
    printf("%d\n",ans);
    return 0;
}
