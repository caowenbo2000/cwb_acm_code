#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<iostream>
#include<list>
#include<stack>
#include<deque>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
struct node
{
    int v;
    long long w;
}temp;
vector<node> G[310];
int vis[305];
queue <int> q;
int from;
int to;
long long dis[305];
int oq[305];
int m,n;
bool spfa(int x)
{
    for(int i=0;i<=n;i++) dis[i]=1e18;
    while(q.size()) q.pop();
    int tmp;
    q.push(x);
    vis[x]=1;
    dis[x]=0;
    while(q.size())
    {
        tmp=q.front();
        q.pop();
        vis[tmp]=0;
        oq[tmp]++;//出队次数
        if(oq[tmp]>=n) return true;
        for(int i=0;i<G[tmp].size();i++)
        {
            node c=G[tmp][i];
            if(dis[tmp]+c.w<dis[c.v])
            {
                dis[c.v]=dis[tmp]+c.w;
                if(vis[c.v]==0)
                {
                    vis[c.v]=1;
                    q.push(c.v);
                }
            }
        }

    }
    if(dis[x]<0) return true;
    return false;
}
bool check(long long x)
{
    memset(oq,0,sizeof(oq));
    memset(vis,0,sizeof(vis));
    temp.v=to;
    temp.w=x;
    //cout<<from<<" "<<to<<endl;
    G[from].push_back(temp);
    bool ok=spfa(to);
    G[from].pop_back();
    return ok;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=1;i<=m;i++)
        {
            int tmp1;
            scanf("%d%d%lld",&tmp1,&temp.v,&temp.w);
            G[tmp1].push_back(temp);
        }
        int ti=1;
        while(ti<=6)
        {
            scanf("%d%d",&from,&to);
            long long l=-1e9,r=1e9;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                //cout<<mid<<endl;
                if(check(mid)) l=mid+1;
                else r=mid-1;
            }
            temp.v=to;
            temp.w=l;
            G[from].push_back(temp);
            printf("%lld\n",l);
            ti++;
        }
    }
    return 0;
}
