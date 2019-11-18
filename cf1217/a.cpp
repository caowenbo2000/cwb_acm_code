#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long str,in,exp;
        scanf("%lld%lld%lld",&str,&in,&exp);
        long long l=0,r=exp;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(str+mid>in+exp-mid) r=mid-1;
            else l=mid+1;
        }
        if(str+exp<=in)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n",exp-l+1);
        }
    }
}
