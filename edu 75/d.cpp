#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
PII p[200005];
bool vis[200005];
long long s;
int n;
bool check(int x)
{
    vector<PII>ve;
    int cnt1=0;
    int cnt2=0;
    int num=0;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i].second<x)
        {
            sum+=p[i].second;
            cnt1++;
        }
        else if(p[i].first>x)
        {
            sum+=p[i].first;
            cnt2++;
        }
        else ve.push_back(p[i]);
    }
    if(cnt1>n/2||cnt2>n/2)
    {
        return 0;
    }
    num=n/2-cnt1;
    sort(ve.begin(),ve.end());
    for(auto v:ve)
    {
        if(num)
        {
            sum+=v.first;
            num--;
        }
        else
        {
            sum+=x;
        }
    }
    return s>=sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l=0,r=0;
        scanf("%d%lld",&n,&s);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i].first,&p[i].second);
            r=max(r,p[i].second);
        }
        sort(p+1,p+1+n);
        l=p[n/2+1].first;
        int mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid))//keyi
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        printf("%d\n",r);
    }
}
