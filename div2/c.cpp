#include<bits/stdc++.h>
using namespace std;
int G[10][10];
int GG[10][10];
int main()
{
    int n;
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        int tmp1,tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        G[tmp2][tmp1]=1;
        G[tmp1][tmp2]=1;
    }
    int ans=0;
    if(n<=6)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                if(G[i][j]==1)
                {
                    ans++;
                }
            }
        }
    }
    else
    {
        for(int k=1; k<=n; k++)//meile
        {
            for(int l=1; l<k; l++)
            {
                int tmp=0;
                for(int i=1; i<=n; i++)
                {
                    for(int j=1; j<=n; j++)
                    {
                        GG[i][j]=G[i][j];
                    }
                }
                for(int i=1; i<=n; i++)//hengbingdiao
                {
                    if(G[i][k])
                    {
                        GG[i][l]=1;
                    }
                    if(G[k][i])
                    {
                        GG[l][i]=1;
                    }
                }
                for(int i=1; i<=n; i++)
                {
                    for(int j=1; j<=i; j++)
                    {
                        if(i!=k&&j!=k&&GG[i][j])
                        {
                            tmp++;
                        }
                    }
                }
                ans=max(ans,tmp);
            }

        }
    }
    printf("%d\n",ans);
}
