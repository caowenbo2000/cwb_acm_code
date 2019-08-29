#include<bits/stdc++.h>
using namespace std;
int mat[55][55];

 const int maxn=55;
 int nx,ny;//x集合和y集合中顶点的个数
 int edge[maxn][maxn];//edge[i][j]为1表示ij可以匹配
 int cx[maxn],cy[maxn];//用来记录x集合中匹配的y元素是哪个！
 int visited[maxn];//用来记录该顶点是否被访问过！
 int path(int u)//寻找是否能够匹配
 {
     int v;
     for(v=1;v<=ny;v++)
     {
         if(edge[u][v]&&!visited[v])
         {
             visited[v]=1;
            if(cy[v]==-1||path(cy[v]))//如果y集合中的v元素没有匹配或者是v已经匹配，但是从cy[v]中能够找到一条增广路
             {
                 cx[u]=v;
                 cy[v]=u;
                 return 1;
             }
         }
     }
     return 0;
 }
 int maxmatch()
 {
     int res=0;
     memset(cx,0xff,sizeof(cx));//初始值为-1表示两个集合中都没有匹配的元素！
     memset(cy,0xff,sizeof(cy));
     for(int i=1;i<=nx;i++)
     {
         if(cx[i]==-1)
         {
             memset(visited,0,sizeof(visited));
             res+=path(i);
         }
     }
     return res;
 }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        char s1[105];
        char s2[105];
        memset(mat,0,sizeof(mat));
        memset(edge,0,sizeof(edge));
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s1+1);
            scanf("%s",s2+1);
            //memset(mat,0,sizeof(mat));
            //memset(edge,0,sizeof(edge));
            for(int j=1;j<=m;j++)
            {
                for(int k=1;k<=m;k++)
                {
                    if(s1[j]==s2[k]) mat[j][k]++;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mat[i][j]==n) edge[i][j]++,edge[j][i]++;
                cout<<mat[i][j];
            }
            cout<<endl;
        }
        nx=m;
        ny=m;
        //cout<<"1"<<endl;
        cout<<maxmatch()<<endl;
        if(maxmatch()==m)
        {
            for(int i=1;i<=m;i++)
            {
                printf("%d%s",cx[i],i==m?"\n":" ");
            }
        }
        else
        {
            printf("-1\n");
        }
    }
}




