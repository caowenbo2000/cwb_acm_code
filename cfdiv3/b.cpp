#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
int vis[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==0)
            {
                int tmp=1;
                int pos=a[i];
                while(pos!=i)
                {
                    tmp++;
                    pos=a[pos];
                }
                ans[i]=tmp;
                pos=a[i];
                while(pos!=i)
                {
                    ans[pos]=tmp;
                    pos=a[pos];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d%s",ans[i],i==n?"\n":" ");
        }
    }
}
