#include<bits/stdc++.h>
using namespace std;
int a[500005];
int l[500005];
int r[500005];
stack<int> st;
long long s[500005];
long long MIN[500005*4],MAX[500005*4];
void build(int root,int l,int r)
{
    if(l==r)
    {
        MIN[root]=s[l];
        MAX[root]=s[r];
        return ;
    }
    int mid=(l+r)/2;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
    MIN[root]=min(MIN[root*2],MIN[root*2+1]);
    MAX[root]=max(MAX[root*2],MAX[root*2+1]);
    return;
}
long long q(int root,int l,int r,int ll,int rr,int tp)
{
    if(ll<=l&&r<=rr)
    {
        if(tp==0) return MIN[root];
        if(tp==1) return MAX[root];
    }
    int mid=(l+r)/2;
    if(rr<=mid) return q(root*2,l,mid,ll,rr,tp);
    else if(ll>mid) return q(root*2+1,mid+1,r,ll,rr,tp);
    else
    {
        if(tp==0) return min(q(root*2,l,mid,ll,rr,tp),q(root*2+1,mid+1,r,ll,rr,tp));
        if(tp==1) return max(q(root*2,l,mid,ll,rr,tp),q(root*2+1,mid+1,r,ll,rr,tp));
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n; i>=1; i--)
    {
        while(st.size()&&a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(st.size()==0)
        {
            r[i]=n;
        }
        else
        {
            r[i]=st.top()-1;
        }
        st.push(i);
    }
    while(st.size())
    {
        st.pop();
    };
    for(int i=1; i<=n; i++)
    {
        while(st.size()&&a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(st.size()==0)
        {
            l[i]=1;
        }
        else
        {
            l[i]=st.top()+1;
        }
        st.push(i);
    }
    s[0]=0;
    for(int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+a[i];
    }
    build(1,0,n);
    long long ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            ans=max(ans,a[i]*(s[r[i]]-s[l[i]-1]));
            printf("%d %d\n",1,ans);
        }
        else
        {
            long long tMIN=q(1,0,n,i,r[i],0);
            long long tMAX=q(1,0,n,l[i]-1,i,1);
//            cout<<tMIN<<" "<<tMAX<<endl;
            ans=max(ans,a[i]*(tMIN-tMAX));
        }
    }
    printf("%lld\n",ans);
}
