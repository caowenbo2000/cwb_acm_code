#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    long long a,b,n,s;
    scanf("%lld%lld%lld%lld",&a,&b,&n,&s);
    long long num=min(s/n,a);
    num=s-num*n;
    if(num<=b)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    }
}
