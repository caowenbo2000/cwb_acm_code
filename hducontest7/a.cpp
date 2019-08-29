#include<bits/stdc++.h>
using namespace std;
int mat[55][55];

 const int maxn=55;
 int nx,ny;//x���Ϻ�y�����ж���ĸ���
 int edge[maxn][maxn];//edge[i][j]Ϊ1��ʾij����ƥ��
 int cx[maxn],cy[maxn];//������¼x������ƥ���yԪ�����ĸ���
 int visited[maxn];//������¼�ö����Ƿ񱻷��ʹ���
 int path(int u)//Ѱ���Ƿ��ܹ�ƥ��
 {
     int v;
     for(v=1;v<=ny;v++)
     {
         if(edge[u][v]&&!visited[v])
         {
             visited[v]=1;
            if(cy[v]==-1||path(cy[v]))//���y�����е�vԪ��û��ƥ�������v�Ѿ�ƥ�䣬���Ǵ�cy[v]���ܹ��ҵ�һ������·
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
     memset(cx,0xff,sizeof(cx));//��ʼֵΪ-1��ʾ���������ж�û��ƥ���Ԫ�أ�
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




