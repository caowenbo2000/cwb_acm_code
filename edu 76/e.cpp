#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int main()
{
    int n1,n2,n3;
    scanf("%d%d%d",&n1,&n2,&n3);
    int tmp;
    for(int i=1;i<=n1;i++)
    {
        scanf("%d",&tmp);
        a[tmp]=1;
    }
    for(int i=1;i<=n2;i++)
    {
        scanf("%d",&tmp);
        a[tmp]=2;
    }
    for(int i=1;i<=n3;i++)
    {
        scanf("%d",&tmp);
        a[tmp]=3;
    }
    int pos=0;
    for(int i=1;i<=n1+n2+n3;i++)
    {
        if(a[i]>=dp[pos])
        {
            dp[++pos]=a[i];
        }
        else
        {
            int cur=upper_bound(dp+1,dp+pos,a[i])-dp;
            dp[cur]=a[i];
        }
    }
    printf("%d\n",n1+n2+n3-pos);
}
