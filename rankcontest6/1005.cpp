#include<bits/stdc++.h>
using namespace std;
int x[2005];
int y[2005];
int z[2005];
map<int,int> mpx;
map<int,int> mpy;
long long a[2005][2005];
long long sum[2005][2005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mpx.clear();
        mpy.clear();
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
            mpx[x[i]]=1;
            mpy[y[i]]=1;
        }
        int nn=mpx.size();
        int mm=mpy.size();
        int cnt=0;
        for(map<int,int>::iterator it=mpx.begin();it!=mpx.end();it++)
        {
            cnt++;
            it->second=cnt;
        }
        cnt=0;
        for(map<int,int>::iterator it=mpy.begin();it!=mpy.end();it++)
        {
            cnt++;
            it->second=cnt;
        }
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            a[mpx[x[i]]][mpy[y[i]]]=z[i];
            //cout<<mpx[x[i]]<<" "<<mpy[y[i]]<<z[i]<<endl;
        }
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=nn;i++)//ºáÏòÇóºÍ
        {
            for(int j=1;j<=mm;j++)
            {
                sum[i][j]=sum[i][j-1]+a[i][j];
            }
        }
        for(int j=1;j<=mm;j++)
        {
            for(int i=2;i<=nn;i++)
            {
                sum[i][j]=sum[i-1][j]+sum[i][j];
                //cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int x1,y1,x2,y2;
                x1=mpx[min(x[i],x[j])];
                x2=mpx[max(x[i],x[j])];
                y1=mpy[min(y[i],y[j])];
                y2=mpy[max(y[i],y[j])];
                ans=max(ans,sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
            }
        }
        printf("%lld\n",sum[nn][mm]);
        printf("%lld\n",ans);
    }
}
