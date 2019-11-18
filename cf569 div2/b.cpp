#include<bits/stdc++.h>
using namespace std;
int vis[1000005];
int a[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        queue<int>q;
        int n,k,d;
        scanf("%d%d%d",&n,&k,&d);
        for(int i=1;i<=k;i++) vis[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int pos=0;
        int ans=1e9;
        for(int i=1;i<=d;i++)
        {
            vis[a[i]]++;
            if(vis[a[i]]==1) pos++;
            q.push(a[i]);
        }
        ans=pos;
        for(int i=d+1;i<=n;i++)
        {
            vis[q.front()]--;
            if(vis[q.front()]==0) pos--;
            q.pop();
            q.push(a[i]);
            vis[a[i]]++;
            if(vis[a[i]]==1) pos++;
            ans=min(pos,ans);
        }
        printf("%d\n",ans);
    }
}
