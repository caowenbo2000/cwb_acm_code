#include<bits/stdc++.h>
using namespace std;
int dp[10][10][10][10];
void bfs(int s,int e,int x,int y)
{
    queue<pair<int,int> >q;
    q.push(make_pair(s,0));
    int vis[10];
    memset(vis,0,sizeof(vis));
    pair<int,int> tmp;
    int flag=0;
    while(q.size())
    {
        tmp=q.front();
        if(tmp.first==e&&flag!=0) {dp[s][e][x][y]=tmp.second-1;return ;}
        q.pop();
        if(vis[(tmp.first+x)%10]==0)
        {
            vis[(tmp.first+x)%10]=1;
            q.push(make_pair((tmp.first+x)%10,tmp.second+1));
        }
        if(vis[(tmp.first+y)%10]==0)
        {
            vis[(tmp.first+y)%10]=1;
            q.push(make_pair((tmp.first+y)%10,tmp.second+1));
        }
        flag=1;
    }
}
char s[2000005];
int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    bfs(i,j,k,l);
                }
            }
        }
    }
    scanf("%s",s+1);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            long long ans=0;
            for(int k=2;s[k];k++)
            {
                if(dp[s[k-1]-'0'][s[k]-'0'][i][j]==-1)
                {
                    ans=-1;
                    break;
                }
                else
                {
                     ans+=dp[s[k-1]-'0'][s[k]-'0'][i][j];
                }
            }
            printf("%lld%s",ans,j==9?"\n":" ");
        }
    }
}
