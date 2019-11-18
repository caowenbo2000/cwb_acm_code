#include<bits/stdc++.h>
using namespace std;
int a[105];
int pos[105];
int vis[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        vector<int>a;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            a.push_back(tmp);
            pos[tmp]=i;
        }
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]!=0) continue;
            if(pos[i]>cur)
            {
                for(int j=pos[i];j>cur;j--)
                {
                    swap(a[j],a[j-1]);
                }
                for(int j=pos[i]-1;j>=cur;j--)
                {
                    vis[a[j]]++;
                }
                cur=pos[i];
            }
            else if(i==a[cur]) cur++,vis[i]++;
        }
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
}
