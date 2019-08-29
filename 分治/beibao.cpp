#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long quick_pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        long long n=a+b+c+d;
        long long sum=0;
        sum=(sum+(b+1)*(quick_pow(2,c)-1)%mod*quick_pow(2,a))%mod;
        sum=(sum+quick_pow(2,a+b))%mod;
        if(d) sum=(sum+d*quick_pow(2,a+c))%mod;
        printf("%lld\n",sum);
    }
}
