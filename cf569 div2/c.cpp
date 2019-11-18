#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    int ans=-1;
    for(int i=1;i<=100;i++)
    {
        int num=n-i*p;
        if(num<=0) break;
        int cnt=0;
        while(num)
        {
            if(num%2) cnt++;
            num/=2;
        }
        num=n-i*p;
        if(cnt<=i&&i<=num)
        {
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
}
