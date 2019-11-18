#include<bits/stdc++.h>
using namespace std;
long long dp[11][150][105];
long long s[150],num[150];// 分别记录数 和 1的个数
int topp=0;
int main()
{
    int n,kk;
    scanf("%d%d",&n,&kk);
    for(int i=0;i<(1<<n);i++)
    {
        if(i&(i<<1)) continue;
        topp++;
        s[topp]=i;
        int tmp=i;
        while(tmp)
        {
            if(tmp&1) num[topp]++;
            tmp/=2;
        }
    }
    dp[0][1][0]=1;
    for(int i=1;i<=n;i++)//最外层枚举行数
    {
        for(int j=1;j<=topp;j++)
        {
            for(int k=1;k<=topp;k++)
            {
                for(int l=0;l<=kk-num[k];l++)
                {
                    if((s[j]&(s[k]<<1))==0&&((s[j]<<1)&s[k])==0&&(s[j]&s[k])==0)
                    {
                        dp[i][k][l+num[k]]+=dp[i-1][j][l];
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=topp;i++)
    {
        ans+=dp[n][i][kk];
    }
    printf("%lld\n",ans);
}
