//written by cwb
#include<bits/stdc++.h>
using namespace std;
int m;
int judge(long long n,long long x)//第m个和n互质的数是不是x
{
    int cnt=0;
    long long tmp;
    for(long long i=n+1;i<=n+1000;i++)
    {
        if(__gcd(i,n)==1) cnt++;
        if(cnt==m) {tmp=i;break;}
    }
    return tmp==x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        long long k;
        long long ans=1e18;
        scanf("%lld%d",&k,&m);
        for(long long i=1;i<=1000;i++)
        {
            n=i^k;
            //cout<<n<<endl;
            if(judge(n,n+i)) {ans=min(ans,n);}
        }
        if(ans==1e18)
        {
            printf("-1\n");
        }
        else
        printf("%lld\n",ans);
    }
}
