#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,a,b;
        scanf("%d%d%d%d",&n,&x,&a,&b);
        printf("%d\n",min(n-1,abs(a-b)+x));
    }
}
