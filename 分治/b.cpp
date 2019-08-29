#include<bits/stdc++.h>
using namespace std;
pair<double,double> p[100005];
int arr[100005];
double dis (int x,int y)
{
    return sqrt((p[x].first-p[y].first)*(p[x].first-p[y].first)+(p[x].second-p[y].second)*(p[x].second-p[y].second));
}
int cmp_y(int x,int y)
{
    return p[x].second>p[y].second;
}

double solve(int s,int e)
{
    if(s+1==e) return dis(s,e);
    else if(s+2==e) return min(dis(s,e),min(dis(s+1,e),dis(s,s+1)));
    int mid=(s+e)/2;
    int cnt=0;
    double ans=min(solve(s,mid),solve(mid+1,e));
    for(int i=s; i<=e; i++)
    {
        if(p[i].first>=p[mid].first-ans&&p[i].first<=p[mid].first+ans)
        {
            arr[++cnt]=i;
        }
    }
    for(int i=1; i<=cnt; i++)
    {
        for(int j=i+1; j<=cnt; j++)
        {
            ans=min(ans,dis(arr[i],arr[j]));
        }
    }
    return ans;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf",&p[i].first,&p[i].second);
        }
        sort(p+1,p+1+n);
        double ans=solve(1,n)/2;
        printf("%.2lf\n",ans);
    }
}
