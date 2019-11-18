#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]==1)
            {
                ans++;
            }
        }
        if(ans==1) puts("1");
        else puts("2");
    }
}
