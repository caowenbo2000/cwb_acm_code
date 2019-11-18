#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    int b,g,n;
    int tmp;
    scanf("%d%d%d",&b,&g,&n);
    for(int i=0;i<=b;i++)
    {
        tmp=n-i;
        if(tmp>=0&&tmp<=g)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
}
