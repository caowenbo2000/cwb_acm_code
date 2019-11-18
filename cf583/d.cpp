#include<bits/stdc++.h>
using namespace std;
int n,m;
char mp[1000005];
int vis[1000005];
int ok[1000005];
int dfsn[1000005];
int dfs(int num,int step)
{
    if(num==m*n-1) return ok[num]=1;
    if(vis[num]==1) return ok[num];
   // dfsn[step]++;
    vis[num]=1;
    int x=num/m;
    int y=num%m;
    int  xx=x;
    int yy=y;
    ++xx;
    int  ans=0;
    if(xx<n&&yy<m&&mp[xx*m+yy]=='.')
    {
        ans|=dfs(xx*m+yy,step+1);
    }
    --xx;
    ++yy;
    if(xx<n&&yy<m&&mp[xx*m+yy]=='.')
    {
        ans|=dfs(xx*m+yy,step+1);
    }
    ok[num]=ans;
    if(ans==1)
    {
        dfsn[step]++;
    }
    return ans;
}
int main()
{
    memset(ok,-1,sizeof(ok));
    scanf("%d%d",&n,&m);
    char *p=mp;
    for(int i=1; i<=n; i++)
    {
        scanf("%s",p);
        p+=m;
    }
    if(dfs(0,0)==0)
    {
        printf("0\n");
    }
    else
    {
        int flag=0;
        for(int i=1;i<n+m-2;i++)
        {
            if(dfsn[i]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("1\n");
        }
        else
        {
            puts("2");
        }
    }
}
