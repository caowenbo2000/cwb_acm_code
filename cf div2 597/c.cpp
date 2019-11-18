#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long dp[100005];
const long long mod=1e9+7;
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    int flag=0;
    if(s[1]=='m'||s[1]=='w')flag=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w') flag=1;
        if(s[i]=='n'&&s[i-1]=='n'||s[i]=='u'&&s[i-1]=='u') dp[i]=(dp[i]+dp[i-2])%mod;
        dp[i]=(dp[i]+dp[i-1])%mod;
    }
    if(flag)printf("0\n");
    else
    printf("%lld\n",dp[n]);
}
