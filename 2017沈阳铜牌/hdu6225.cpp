#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long a,b,c,d;
        scanf("%llu%llu%llu%llu",&a,&b,&c,&d);
        if(a==1LL<<62&&b==1LL<<62&&c==1LL<<62&&d==1LL<<62)
        {
            printf("18446744073709551616\n");
        }
        else
        printf("%llu\n",a+b+c+d);
    }
}
