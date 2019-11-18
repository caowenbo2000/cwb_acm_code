#include<bits/stdc++.h>
using namespace std;
long long a(long long n,long long mod)
{
    long long res=1;
    for(int i=1;i<=n;i++)
    {
        res=(res*i)%mod;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k,q;
        scanf("%lld%lld%lld",&n,&k,&q);
        long long ans=1;
        if(k>=n)
        {
            printf("%lld\n",a(n,q));
        }
        else
        {
            ans=(a(k,q)%q*((n-k)*(n-k-1)-(0==n-k-1?0:1)+(k)*(n-k)+(n-k-1))+1)%q;
            cout<<a(k,q)*((n-k)*(n-k-1)-(0==n-k-1?0:1))<<endl;
            cout<<a(k,q)*(k)*(n-k)<<endl;
            cout<<a(k,q)*(n-k-1)<<endl;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
