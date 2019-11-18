#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long q_p(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2) ans=(ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        long long tmp=q_p(2,n-1);
        //cout<<tmp<<endl;
        long long x=n%mod*q_p(tmp,mod-2)%mod;
        printf("%lld\n",x);
    }
}
