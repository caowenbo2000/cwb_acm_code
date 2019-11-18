#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        map<int,int>mp;
        int n;
        scanf("%d",&n);
        int ans=1e9+1;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(mp[tmp]!=0)
            {
                ans=min(ans,i-mp[tmp]+1);
                mp[tmp]=i;
            }
            else mp[tmp]=i;
        }
        if(ans>=1000000000) printf("-1\n");
        else printf("%d\n",ans);
    }
}
