#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long long p;
    long long q;
    scanf("%lld%lld%lld",&n,&p,&q);
    q*=5;
    long long ans=100000000000;
    long long pos=0;
    while(pos<=n)
    {
        ans=min(ans,(n-pos)%q);
        pos+=p;
    }
    printf("%lld\n",ans);
}
