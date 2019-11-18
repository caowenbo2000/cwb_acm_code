#include<bits/stdc++.h>
using namespace std;
signed main()
{
    long long n;
    scanf("%I64d",&n);
    int cnt=0;
    long long tmp=n;
    long long ans=0;
    for(long long i=2; i*i<=n; i++)
    {
        if(tmp%i==0)
        {
            ans=i;
            cnt++;
            while(tmp%i==0)
            {
                tmp/=i;
            }
        }
    }
    if(tmp!=1&&tmp!=n) cnt++;
    if(cnt==0)
    {
        printf("%I64d\n",n);
    }
    else if(cnt==1)
    {
        printf("%I64d\n",ans);
    }
    else
    {
        printf("1\n");
    }
}
