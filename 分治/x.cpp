//by cwb
#include<bits/stdc++.h>
using namespace std;
map<int,int>mpx;
map<int,int>mpy;
int G[12][12];
int vis[12][12];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int cntx,cnty;
int dfs(int y,int x)
{
    vis[y][x]=1;
    for(int i=0;i<=3;i++)
    {
        int xx=x+dir[i][1];
        int yy=y+dir[i][0];
        if(xx>=1&&xx<=cntx&&yy>=1&&yy<=cnty&&vis[yy][xx]==0&&G[yy][xx]==0)
        {
            dfs(yy,xx);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mpx.clear();
        mpy.clear();
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int x3,y3,x4,y4;
        scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
        mpx[x1]++;
        mpx[x2]++;
        mpx[x3]++;
        mpx[x4]++;
        mpy[y1]++;
        mpy[y2]++;
        mpy[y3]++;
        mpy[y4]++;
        cntx=0;
        for(map<int,int>::iterator it=mpx.begin();it!=mpx.end();it++)
        {
            cntx+=2;
            it->second=cntx;
            //cout<<it->first<<" "<<it->second<<endl;
        }
        cntx+=2;
        cnty=0;
        for(map<int,int>::iterator it=mpy.begin();it!=mpy.end();it++)
        {
            cnty+=2;
            it->second=cnty;
            // cout<<it->first<<" "<<it->second<<endl;
        }
        cnty+=2;
        for(int i=0;i<=cntx;i++)
        {
            if(i>=mpx[x1]&&i<=mpx[x2])
            {
                G[mpy[y1]][i]=1;
                G[mpy[y2]][i]=1;
            }
            if(i>=mpx[x3]&&i<=mpx[x4])
            {
                G[mpy[y3]][i]=1;
                G[mpy[y4]][i]=1;
            }
        }
        for(int i=0;i<=cnty;i++)
        {
            if(i>=mpy[y1]&&i<=mpy[y2])
            {
                G[i][mpx[x1]]=1;
                G[i][mpx[x2]]=1;
            }
            if(i>=mpy[y3]&&i<=mpy[y4])
            {
                G[i][mpx[x3]]=1;
                G[i][mpx[x4]]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=cnty;i++)
        {
            for(int j=1;j<=cntx;j++)
            {printf("%01d",G[i][j]);
                if(vis[i][j]==0&&G[i][j]==0)
                {
                    //ans++;
                    //dfs(i,j);

                }
            }
            cout<<endl;
        }
        printf("%d\n",ans);
    }
}
