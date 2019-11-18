#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int a[105];
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        memset(dp,0x3f,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int len=0;len<n;len++)
        {
            for(int i=1;i+len<=n;i++)
            {
                int j=i+len;
                if(len==0) dp[i][j]=1;
                for(int k=i+1;k<=j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]-(a[i]==a[k]));
                }
            }
        }
        printf("Case %d: %d\n",cas++,dp[1][n]);
    }
}
