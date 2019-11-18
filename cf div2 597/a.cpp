#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int num=__gcd(a,b);
        if(num==1)
        {
            printf("Finite\n");
        }
        else
        {
            printf("Infinite\n");
        }
    }

}
