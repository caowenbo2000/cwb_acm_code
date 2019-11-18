#include<bits/stdc++.h>
using namespace std;
int dp[2][200005];
int a[200005];
int b[200005];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=2;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)scanf("%d",&b[i]);
    dp[0][1]=0;
    dp[1][1]=c;
    for(int i=2;i<=n;i++)
    {
        dp[1][i]=min(c+b[i]+dp[0][i-1],dp[1][i-1]+b[i]);
        dp[0][i]=min(dp[0][i-1]+a[i],dp[1][i-1]+a[i]);
    }
    for(int i=1;i<=n;i++)
    printf("%d ",min(dp[0][i],dp[1][i]));
}
