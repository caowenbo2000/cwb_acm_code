#include<cstdio>
#include<iostream>
using namespace std;
long long fac[2005];
long long inv[2005];
const long long mod=1000000007;
long long q_pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}

int main()
{
    int t;
    fac[0]=1;
    for(long long i=1;i<=2000;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        //cout<<fac[i]<<mod-2<<endl;
        inv[i]=q_pow(fac[i],1000000005);

    }
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==1||m==1) printf("%d\n",1);
        else
        {
            long long ans;
            ans=fac[m+n-2]*inv[m-1]%mod*inv[n-1]%mod;
            printf("%lld\n",ans);
        }
    }
}
