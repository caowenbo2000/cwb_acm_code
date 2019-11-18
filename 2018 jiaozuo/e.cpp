#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        long long ans=1;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0) ans*=j;
        }
        printf("%d->",i);
        long long tmp=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0) tmp+=(ans/j);
        }
        long long sb=__gcd(tmp,ans);
//        tmp/=sb;
//        ans/=sb;
        printf("%lld/%lld\n",ans,tmp);
    }
}
