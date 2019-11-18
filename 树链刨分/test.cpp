#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int first[MAXN],nxt[MAXN],to[MAXN],topp=0;
int sum[MAXN*4],maxx[MAXN*4],num[MAXN];
int son[MAXN],father[MAXN],top[MAXN],siz[MAXN],id[MAXN],rk[MAXN],pos=0,dep[MAXN];
int n,m;
void add(int u,int v)
{
    topp++;
    nxt[topp]=first[u];
    first[u]=topp;
    to[topp]=v;

    topp++;
    nxt[topp]=first[v];
    first[v]=topp;
    to[topp]=u;
}
void dfs(int x,int deep)//搞好重链
{
    dep[x]=deep;
    siz[x]=1;
    int tmp=0;
   for(int i=first[x];~i;i=nxt[i])
   {
       int v=to[i];
       if(father[x]==v) continue;
       father[v]=x;
       dfs(v,deep+1);
       siz[x]+=siz[v];
       if(siz[v]>tmp) son[x]=v,tmp=siz[v];
   }
   return ;
}
void dfs2(int x,int nowtop)//id节点所对应后的编号 rk序列所对应的数字  top
{
    top[x]=nowtop;
    pos++;
    id[x]=pos;
    rk[pos]=x;
    if(!son[x]) return;
    dfs2(son[x],nowtop);
    for(int i=first[x];~i;i=nxt[i])
    {
        int v=to[i];
        if(v==father[x]||v==son[x])
        {
            continue;
        }
        dfs2(v,v);
    }
    return ;
}
void build(int root,int l,int r)
{
//    cout<<l<<" "<<r<<endl;
    if(l==r)
    {
        maxx[root]=num[rk[l]];
        sum[root]=num[rk[l]];
         //cout<<maxx[root]<<" "<<sum[root]<<num[r<<endl;
        return ;
    }
    int mid=(l+r)/2;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
    maxx[root]=max(maxx[root*2],maxx[root*2+1]);
    sum[root]=sum[root*2]+sum[root*2+1];
//    cout<<maxx[root]<<" "<<sum[root]<<endl;
    return ;
}
void updata(int root,int l,int r,int x,int num)
{
//    cout<<l<<" "<<r<<endl;
    if(l==r&&r==x)
    {
        maxx[root]=num;
        sum[root]=num;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)
    {
        updata(root*2,l,mid,x,num);
    }
    else
    {
        updata(root*2+1,mid+1,r,x,num);
    }
    maxx[root]=max(maxx[root*2],maxx[root*2+1]);
    sum[root]=sum[root*2]+sum[root*2+1];
}
int qqmax(int root,int ll,int rr,int l,int r)
{
    if(ll<=l&&rr>=r)
    {
        return maxx[root];
    }
    int mid=(l+r)/2;
    if(rr<=mid) return qqmax(root*2,ll,rr,l,mid);
    else if(ll>mid) return qqmax(root*2+1,ll,rr,mid+1,r);
    else return max(qqmax(root*2,ll,rr,l,mid),qqmax(root*2+1,ll,rr,mid+1,r));
}
int qqsum(int root,int ll,int rr,int l,int r)
{
    if(ll<=l&&rr>=r)
    {
        return sum[root];
    }
    int mid=(l+r)/2;
    if(rr<=mid) return qqsum(root*2,ll,rr,l,mid);
    else if(ll>mid) return qqsum(root*2+1,ll,rr,mid+1,r);
    else return qqsum(root*2,ll,rr,l,mid)+qqsum(root*2+1,ll,rr,mid+1,r);
}
int qmax(int x,int y)
{
    int ans=-1e9;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
        {
            ans=max(ans,qqmax(1,id[top[y]],id[y],1,n));
            y=father[top[y]];
        }
        else
        {
            ans=max(ans,qqmax(1,id[top[x]],id[x],1,n));
            x=father[top[x]];
        }
    }
//    cout<<"x"<<endl;
    if(x==y)
    {
        ans=max(ans,num[x]);
    }
    if(dep[x]<dep[y])
    {
        ans=max(ans,qqmax(1,id[x],id[y],1,n));
    }
    if(dep[x]>dep[y])
    {
        ans=max(ans,qqmax(1,id[y],id[x],1,n));
    }
    return ans;
}
int qsum(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
        {
            ans+=qqsum(1,id[top[y]],id[y],1,n);
            y=father[top[y]];
        }
        else
        {
            ans+=qqsum(1,id[top[x]],id[x],1,n);
            x=father[top[x]];
        }
    }
    if(x==y)
    {
        ans+=num[x];
    }
    if(dep[x]<dep[y])
    {
        ans+=qqsum(1,id[x],id[y],1,n);
    }
    if(dep[x]>dep[y])
    {
        ans+=qqsum(1,id[y],id[x],1,n);
    }
    return ans;
}
int main()
{
    father[1]=1;
    memset(first,-1,sizeof(first));
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int tmp1,tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        add(tmp1,tmp2);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    dfs(1,1);
    dfs2(1,1);
    build(1,1,n);
//    cout<<qqsum(1,1,4,1,4);
    scanf("%d",&m);
    while(m--)
    {
        char op[20];
        scanf("%s",op);
        int tmp1,tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        if(op[1]=='H')//更新节点
        {
            num[tmp1]=tmp2;
            updata(1,1,n,id[tmp1],tmp2);
        }
        if(op[1]=='M')//最大值
        {
            printf("%d\n",qmax(tmp1,tmp2));
        }
        if(op[1]=='S')//求和
        {
            printf("%d\n",qsum(tmp1,tmp2));
        }
    }
}
