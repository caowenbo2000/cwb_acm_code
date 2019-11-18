#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        while(n%5==0)
        {
            n/=5;
        }
        while(n%2==0)
        {
            n/=2;
        }
        if(n==1)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}
