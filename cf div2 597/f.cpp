#include<bits/stdc++.h>
#define int long long
using namespace std;
int ar[50];
int br[50];
int dp[50][2][2];
int dfs(int pos,int lim1,int lim2)
{
    if(pos==0) return 1;
    int ans=0;
    if(dp[pos][lim1][lim2]!=-1)
    {
        return dp[pos][lim1][lim2];
    }
    int sa=lim1?ar[pos]:1;
    int sb=lim2?br[pos]:1;
    for(int i=0;i<=sa;i++)
    {
        for(int j=0;j<=sb;j++)
        {
            if((i&j)==0)
            {
                ans+=dfs(pos-1,lim1&(sa==i),lim2&(sb==j));
            }
        }
    }
    dp[pos][lim1][lim2]=ans;
    return ans;
}
int solve(int a,int b)
{
    if(a<0||b<0) return 0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=31;i++)
    {
        ar[i]=a&1;
        br[i]=b&1;
        a/=2;
        b/=2;
//        cout<<ar[i]<<endl;
    }
    return dfs(31,1,1);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",solve(b,b)-2*solve(a-1,b)+solve(a-1,a-1));
    }
}

