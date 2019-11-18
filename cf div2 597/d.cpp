#include<bits/stdc++.h>
using namespace std;
struct node
{
    pair<int,int>cood;
    int cost;
    int k;
} v[2005];

struct EDGE
{
    long long c;
    int u,v;
    int typ;
    bool friend operator  <(EDGE p,EDGE q)
    {
        return p.c<q.c;
    }
};

vector<EDGE>edge;

int dis(int p,int q)
{
    return abs(v[p].cood.first-v[q].cood.first)+abs(v[p].cood.second-v[q].cood.second);
}

int father[2005];
vector<int>ans1;
vector<pair<int,int> >ans2;
int fin(int x)
{
    if(father[x]==x) return x;
    return father[x]=fin(father[x]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<=n; i++) father[i]=i;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&v[i].cood.first,&v[i].cood.second);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&v[i].cost);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&v[i].k);
    }
    EDGE tmp;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if(i==j)
            {
                tmp.u=0;
                tmp.v=i;
                tmp.c=v[i].cost;
                tmp.typ=0;
            }
            else
            {
                tmp.u=i;
                tmp.v=j;
                tmp.c=1LL*(v[i].k+v[j].k)*dis(i,j);
                tmp.typ=1;
            }
            edge.push_back(tmp);
        }
    }
    sort(edge.begin(),edge.end());
    long long ans=0;
    int cnt=0;
//    cout<<edge.size()<<endl;
    for(int i=0; i<edge.size(); i++)
    {
        //cout<<edge[i].v<<" "<<edge[i].u<<" "<<edge[i].c<<endl;
        //cout<<fin(edge[i].v)<<" "<<fin(edge[i].u)<<endl;
        if(fin(edge[i].v)==fin(edge[i].u)) continue;
        else
        {
            father[fin(edge[i].u)]=fin(edge[i].v),ans+=edge[i].c;
            if(edge[i].typ==0)
            {
                if(edge[i].u==0)
                ans1.push_back(edge[i].v);
                else
                ans1.push_back(edge[i].u);
            }
            else
            {
                ans2.push_back(make_pair(edge[i].u,edge[i].v));
            }
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",ans1.size());
    for(int i=0;i<ans1.size();i++)
    {
        printf("%d ",ans1[i]);
    }
    printf("\n%d\n",ans2.size());
    for(int i=0;i<ans2.size();i++)
    {
        printf("%d %d\n",ans2[i].first,ans2[i].second);
    }
}
