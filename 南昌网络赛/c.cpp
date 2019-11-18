#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
vector<P> g[2005];//first dis second to
priority_queue<P,vector<P>,greater<P> > q;
int vis[2005];
int dis[2005];
int po[2005];
signed main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int n,m;
        int s,e;
        int c;
        int k;
        scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&k,&c);
        for(int i=1;i<=k;i++) scanf("%lld",&po[i]);
        memset(vis,0,sizeof(vis));
        while(q.size()) q.pop();
        for(int i=0; i<=n; i++) g[i].clear();
        memset(dis,0x3f,sizeof(dis));
        int tmp1,tmp2,tmp3;
        for(int i=1; i<=m; i++)
        {
            scanf("%lld%lld%lld",&tmp1,&tmp2,&tmp3);
            g[tmp1].push_back(make_pair(tmp3,tmp2));
            g[tmp2].push_back(make_pair(tmp3,tmp1));
        }
        //scanf("%lld%lld",&s,&e);
        q.push(make_pair(0,s));
        dis[s]=0;
        while(q.size())
        {
            int tmp=q.top().second;
            if(vis[tmp]==1)
            {
                q.pop();
                continue;
            }
            q.pop();
            vis[tmp]=1;//选择加入v
            for(vector<P>::iterator it=g[tmp].begin(); it!=g[tmp].end(); it++)
            {
                int pos=dis[tmp]+it->first;
                if(pos<dis[it->second]&&vis[it->second]==0)
                {
                    dis[it->second]=pos;
                    q.push(make_pair(pos,it->second));
                }
            }
        }




        int ans1=0;
        int ans2=0;
        for(int i=1; i<=n; i++)
        {
            ans1=max(ans1,dis[i]);
        }
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        while(q.size()) q.pop();
        for(int i=1;i<=k;i++)
        {
            q.push(make_pair(0,po[i]));
            dis[po[i]]=0;
        }
        while(q.size())
        {
            int tmp=q.top().second;
            if(vis[tmp]==1)
            {
                q.pop();
                continue;
            }
            q.pop();
            vis[tmp]=1;//选择加入v
            for(vector<P>::iterator it=g[tmp].begin(); it!=g[tmp].end(); it++)
            {
                int pos=dis[tmp]+it->first;
                if(pos<dis[it->second]&&vis[it->second]==0)
                {
                    dis[it->second]=pos;
                    q.push(make_pair(pos,it->second));
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans2=max(ans2,dis[i]);
        }
        cout<<ans1<<" "<<ans2<<endl;
        if(ans1=ans2*c)
        {
            printf("%lld\n",ans1);
        }
        else{
            printf("%lld\n",ans2);
        }
    }

}
