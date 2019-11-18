#include<bits/stdc++.h>
using namespace std;
int a[505];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int num=a[n]-a[1]+1-n;
        int MIN=min(a[n]-a[n-1]-1,a[2]-a[1]-1);
        printf("%d\n",num-MIN);
    }
}
