#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        a[1]=0;
        for(int i=2;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            a[i]=a[i-1]+tmp;
        }
        int l=1,r=n;
        long long pos=0;
        long long sum=0;
        int cnt=0;
        while(r-l>0)
        {
            sum+=pos;
            cnt++;
            printf("%lld ",sum);
            sum+=pos;
            sum+=a[r]-a[l];
            pos+=a[r]-a[l];
            cnt++;
            printf("%lld%s",sum,cnt==n?"\n":" ");
            l++;
            r--;
        }
        if(r-l==0)
        {
            printf("%lld\n",sum+pos);
        }
        //printf("\n");
    }
}
