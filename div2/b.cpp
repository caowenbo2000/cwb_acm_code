#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%01d",&a[i]);
    }
    if(n==1&&k)
    {
        printf("0\n");
        return 0;
    }
    if(k&&a[1]!=1)
    {
        k--;
        a[1]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(k) a[i]=0,k--;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
