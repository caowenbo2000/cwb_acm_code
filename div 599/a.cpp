#include<bits/stdc++.h>
using namespace std;
int a[1005];
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
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=n+1-i;
            if(a[j]<i)
            {
                break;
            }
            ans=i;
        }
        printf("%d\n",ans);
    }
}
