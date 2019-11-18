#include<bits/stdc++.h>
using namespace std;
long long p[200005];
long long n;
long long k;
long long x,y,a,b;
int cmp(long long wen,long long bo)
{
    return wen>bo;
}
bool check(long long xx)
{
    long long tmp=0;
    long long num1,num2,num3;
    num3=xx/((a*b)/__gcd(a,b));
    num1=xx/a-num3;
    num2=xx/b-num3;
    //cout<<xx<<" "<<num1<<" "<<num2<<" "<<num3<<endl;
    int i=1;
    while(num3&&i<=n)
    {
        tmp=tmp+(x+y)*p[i];
        num3--;
        i++;
    }
    if(y>x)
    {
        while(num2&&i<=n)
        {
            tmp=tmp+(y)*p[i];
            num2--;
            i++;
        }
        while(num1&&i<=n)
        {
            tmp=tmp+x*p[i];
            num1--;
            i++;
        }
    }
    else
    {
        while(num1&&i<=n)
        {
            tmp=tmp+x*p[i];
            num1--;
            i++;
        }
        while(num2&&i<=n)
        {
            tmp=tmp+(y)*p[i];
            num2--;
            i++;
        }

    }
    //cout<<":"<<xx<<" "<<tmp<<endl;
    return tmp>=k;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&p[i]);
            p[i]/=100;
        }
        scanf("%I64d%I64d%I64d%I64d%I64d",&x,&a,&y,&b,&k);
        sort(p+1,p+1+n,cmp);
        long long  l=0,r=n+1;
        long long mid;
        while(l<=r)
        {
//            cout<<mid<<endl;
            mid=(l+r)/2;
            if(check(mid)) r=mid-1;
            else l=mid+1;
        }
        if(l>=n+1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%I64d\n",l);
        }
    }
}
