#include<bits/stdc++.h>
using namespace std;
char s1[105];
char s2[105];
int dp[105][105];
int f[105];
int main()
{
    while(~scanf("%s",s1+1))
    {
        memset(dp,0x3f,sizeof(dp));
        memset(f,0x3f,sizeof(f));
        scanf("%s",s2+1);
        int n=strlen(s1+1);
        for(int len=0;len<n;len++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+len;
                if(len==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=min(dp[i][j],dp[i+1][j]+(s2[i]!=s2[i+1]));
                dp[i][j]=min(dp[i][j],dp[i+1][j]+(s2[i]!=s2[j]));
                dp[i][j]=min(dp[i][j],dp[i][j-1]+(s2[j]!=s2[j-1]));
                dp[i][j]=min(dp[i][j],dp[i][j-1]+(s2[j]!=s2[i]));
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
//        cout<<dp[1][n]<<" "<<dp[1][1]<<endl;
        f[1]=1;
        f[0]=0;
        for(int i=1;i<=n;i++)
        {

            if(s1[i]==s2[i]) f[i]=f[i-1];
            else
            {
                for(int k=0;k<i;k++)
                {
                    f[i]=min(f[i],f[k]+dp[k+1][i]);
                }
            }
        }
        printf("%d\n",f[n]);
    }
}
