#include <bits/stdc++.h>
using namespace std;
int ans[200005];
long long sum=0;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        sum=0;
        int n;
        scanf("%d", &n);
        int cnt=2;
        for(int i=2;i<=n;i++)
        {
            if(i==(1<<cnt)-1)
            {
                if((1<<cnt)<=n) ans[i]=(1<<cnt);
                else sum++,ans[i]=1;
                cnt++;
            }
            else 
            {
                int tmp=1;
                while(tmp&i)
                {
                    tmp=tmp<<1;
                }
                ans[i]=tmp;
            }
        }
        cout<<sum<<endl;
        for(int i=2;i<=n;i++)
        {
            printf("%d%c",ans[i],i==n?'\n':' ');
        }
    }
}




int l = 1, r = k;
            int mid = 0;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (v[query(1, n, root[x - 1], root[y], mid) - 1] > p)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            vector<int> ve;
            int tmp = mid;
            while (tmp < r - l + 1 && tmp - mid <= k)
            {
                ve.push_back(v[query(1, n, root[x - 1], root[y], tmp) - 1]);
            }
            tmp = mid - 1;
            while (tmp > 1 && mid - tmp <= k)
            {
                ve.push_back(v[query(1, n, root[x - 1], root[y], tmp) - 1]);
            }
            printf("%d\n", ve[k - 1]);