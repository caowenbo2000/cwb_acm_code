#include<bits/stdc++.h>
using namespace std;
long long MOD(long long a,long long b) {return a<b?a:a%b+b;}
long long euler(long long n)
{
    long long res=n,a=n;
    for(long long i=2; i*i<=a; i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
long long q_p(long long a,long long b,long long mod)
{
    long long ans=1;
    while(b)
    {
        if(b%2) ans=MOD((ans*a),mod);
        b/=2;
        a=MOD(a*a,mod);
    }
    return ans;
}
long long solve(long long a,long long b,long long mod)//头上有几个b
{
    long long phi=euler(mod);
    if(b==0||mod==1)
    {
        return MOD(a,mod);
    }
    return q_p(a,solve(a,b-1,phi),mod);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,mod;
        scanf("%lld%lld%lld",&a,&b,&mod);
        if(mod==1) puts("0");
        else if(b==0) puts("1");
        else printf("%lld\n",solve(a,b-1,mod)%mod);
    }
}
