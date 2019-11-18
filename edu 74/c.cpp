#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,h;
        scanf("%d%d",&h,&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int pos=2;
        int ans=0;
        a[0]=-1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1]-1)
            {
                pos++;
            }
            else
            {
                if(pos%2==1&&pos>=3) ans++;
                pos=1;
            }
           if(i==n&&pos!=1)
           {
               if(pos%2==1&&a[i]!=1)
               {
                   ans++;
               }
           }
        }
        printf("%d\n",ans);
    }
}
