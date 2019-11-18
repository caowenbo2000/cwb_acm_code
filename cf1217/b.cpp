#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int t;
    scanf("%I64d",&t);
    while(t--)
    {
        int MAX1=-1000000000,MAX2=-1000000000;
        int n,x;
        scanf("%I64d%I64d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            int tmp1,tmp2;
            scanf("%I64d%I64d",&tmp1,&tmp2);
            MAX1=max(MAX1,tmp1);
            MAX2=max(MAX2,tmp1-tmp2);
        }
        x-=MAX1;
        if(x<=0)
        {
            puts("1");
        }
        else
        {
            if(MAX2<=0)
            {
                puts("-1");
            }
            else
            {
                printf("%I64d\n",1+(x+MAX2-1)/MAX2);
            }
        }
    }
}
