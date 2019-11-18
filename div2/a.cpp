#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10];
    scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
    int flag=0;
    int sum=a[1]+a[2]+a[3]+a[4];
    for(int i=1;i<=4;i++)
    {
        if(a[i]==sum-a[i])
        {
            flag=1;
        }
        for(int j=1;j<=4;j++)
        {
            if(i==j) continue;
            if(a[i]+a[j]==sum-a[i]-a[j])
            {
                flag=1;
            }
        }
    }
    if(flag)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
