#include<bits/stdc++.h>
using namespace std;
int  n,m;
int c[100005];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
struct node
{
    int  l,r;
    int id;
    bool operator < (const node p)const
    {
        return l>p.l;
    }
}q[100005];
int a[100005];
int b[100005];
vector<int>ve[100005];
int ans[100005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;i*j<=n;j++)
        {
            if(b[i]<b[i*j])
            {
                ve[b[i]].push_back(b[i*j]);
            }
            else
            {
                ve[b[i*j]].push_back(b[i]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+1+m);
    int pos=n+1;
    for(int i=1;i<=m;i++)
    {
        for(int j=q[i].l;j<pos;j++)
        {
            for(auto v:ve[j])
            {
                update(v,1);
            }
        }
        pos=q[i].l;
        ans[q[i].id]=sum(q[i].r);
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
