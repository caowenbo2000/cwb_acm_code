#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
P pi[200005];
int n,m,p;
struct node
{
    int x,ly,ry;
    int ans;
    int id;
}qur[200005];
int c[200005];
int cmp1(node p,node q)
{
    return p.x<q.x;
}
int cmp2(node p,node q)
{
    return p.id<q.id;
}
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
int get_num(P cao)
{
    int x=n+1-cao.second;
    int y=cao.first;
    long long tmp=0;
    if(x<=y&&x<n-y+1)//shang
    {   //cout<<"1"<<"_";
        tmp=(long long)4*x*(n+1)-8*x*(x+1)/2;
        tmp-=n-x-y;
    }
    if(x>y&&x<=n-y+1)
    {
        //cout<<"2"<<"_";
        tmp=(long long)4*y*(n+1)-8*y*(y+1)/2;
        tmp-=n+1-2*y;
        tmp-=x-y-1;
    }
    if(x>=y&&x>n-y+1)
    {
        //cout<<"3"<<"_";
        tmp=(long long)4*(n+1-x)*(n+1)-8*(n+1-x)*((n+1-x)+1)/2;
        tmp-=2*n+2-4*(n+1-x);
        tmp-=x-n+y-2;
    }
    if(x<y&&x>=n-y+1)
    {
        //cout<<"4"<<"_";
        tmp=(long long)4*(n+1-y)*(n+1)-8*(n+1-y)*((n+1-y)+1)/2;
        tmp-=3*n+3-6*(n+1-y);
        tmp-=y-x-1;
    }
    if(x==n/2+1&&y==n/2+1)
    {
       tmp=(long long )n*n;
    }
    int ans=0;
    while(tmp!=0)
    {
        ans+=tmp%10;
        tmp/=10;
    }
    return ans;
}
main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&p);
        for(int i=1;i<=m;i++)
        {
            scanf("%lld%lld",&pi[i].first,&pi[i].second);
            //cout<<get_num(pi[i])<<endl;
        }
        sort(pi+1,pi+1+m);
        for(int i=1;i<=p;i++)
        {
            scanf("%lld%lld%lld%lld",&qur[i*2-1].x,&qur[i*2-1].ly,&qur[i*2].x,&qur[i*2].ry);
            qur[i*2-1].x--;
            qur[i*2-1].ly--;
            qur[i*2-1].ry=qur[i*2].ry;
            qur[i*2].ly=qur[i*2-1].ly;
            qur[i*2-1].id=i*2-1;
            qur[i*2].id=i*2;
        }
        //cout<<"#";
        memset(c,0,sizeof(c));
        sort(qur+1,qur+1+p*2,cmp1);
        int pos=1;
        for(int i=1;i<=p*2;i++)
        {
            while(pi[pos].first<=qur[i].x&&pos<=m)
            {
                //cout<<pi[pos].second<<get_num(pi[pos])<<endl;
                update(pi[pos].second,get_num(pi[pos]));
                pos++;
            }
            qur[i].ans=sum(qur[i].ry)-sum(qur[i].ly);
            //cout<<qur[i].id<<" "<<qur[i].ans<<endl;
        }
        sort(qur+1,qur+1+2*p,cmp2);
        for(int i=1;i<=p;i++)
        {
            //printf("%d %d\n",qur[i*2].ans,qur[i*2-1].ans);
            printf("%lld\n",qur[i*2].ans-qur[i*2-1].ans);
        }
    }
    return 0;
}
