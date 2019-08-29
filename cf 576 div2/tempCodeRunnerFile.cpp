#include <bits/stdc++.h>
using namespace std;
int a[400005];
int mp[400005];
int MAX=0;
int sum[400005];
int num;
int main()
{
    //freopen("in.txt","r",stdin);
    int n, I;
    cin >> n >> I;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int cnt=0;
    sort(a + 1, a + 1 + n);
    a[0]=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            mp[cnt]++;
        }
        else
        {
            mp[++cnt]++;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        sum[i]=sum[i-1]+mp[i];
    }
    int num=8*I/n;
    if(num>=19) printf("%d",0);
    else
    {
        num=1<<num;
        int cur;
        for(int i=1;i<=cnt;i++)
        {
            cur=min(cnt,i+num);
            MAX=max(MAX,sum[cur]-sum[i-1]);
        }
    }
    printf("%d\n",n-MAX);
    return 0;
}