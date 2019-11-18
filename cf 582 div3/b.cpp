#include<bits/stdc++.h>
using namespace std;
int a[150005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        priority_queue<int,vector<int> ,greater<int> > q;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans=0;
        for(int i=n;i>=1;i--)
        {
            if(q.size())
            {
                if(a[i]>q.top())
                {
                    ans++;

                }
                else
                {
                    q.push(a[i]);
                }
            }
            else
            {
                q.push(a[i]);
            }
        }
        printf("%d\n",ans);
    }
}
