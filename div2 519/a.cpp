#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        if(x<4) printf("%d\n",4-x);
        else if(x%2==0) printf("0\n");
        else printf("1\n");
    }
}
