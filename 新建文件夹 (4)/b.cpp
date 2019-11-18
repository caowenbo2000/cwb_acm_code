#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int cnt=0;
        int num=0;
        for(int i=n;i>=1;i--)
        {
            if(a[i]-num<=0)
            {
                break;
            }
            cnt++;
            num+=r;
        }
        printf("%d\n",cnt);
    }
}
