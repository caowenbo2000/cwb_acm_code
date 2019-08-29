#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    int a;
    int b;
}x[200005];
int vis[200005];
int ar[200005];
int tmp[200005];
int cmp1(node p,node q)
{
    return p.b<q.b;
}
int cmp2(node p,node q)
{
    return p.a<q.a;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i].a,&x[i].b);
        tmp[i]=x[i].b;
        x[i].id=i;
    }
    sort(x+1,x+n+1,cmp1);
    for(int i=1;i<=n;i++) ar[i]=x[i].id;
    sort(x+1,x+1+n,cmp2);
    int pos=0;
    int num=1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<x[i].a<<pos<<endl;
        if(vis[x[i].id]==1) continue;
        while(pos<x[i].a)
        {
            while(vis[ar[num]]==1) num++;
            ans+=tmp[ar[num]];
            vis[ar[num]]=1;
            pos++;
        }
        if(vis[x[i].id]==0) vis[x[i].id]=1,pos++;
    }
    printf("%lld\n",ans);
}
