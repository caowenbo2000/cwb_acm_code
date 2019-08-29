//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
long long mat[1005][1005];
int ans[1005][1005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++){ mat[i][j]=1e18;}}
        for(int i=1;i<=m;i++)
        {
            int tmp1,tmp2;
            long long tmp3;
            scanf("%d%d%lld",&tmp1,&tmp2,&tmp3);
            mat[tmp1][tmp2]=tmp3;
            mat[tmp2][tmp1]=tmp3;
        }
        for(int i=1;i<=n;i++) mat[i][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(mat[j][k]>mat[j][i]+mat[i][k]) mat[j][k]=mat[j][i]+mat[i][k],ans[j][k]=i;
                }
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sum=(sum+ans[i][j])%998244353;
            }
        }
        printf("%lld\n",sum);
    }
}
