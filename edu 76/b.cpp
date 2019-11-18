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
        if(a==1&&b>a)
        {
            printf("NO\n");
        }
        else if((a==2||a==3)&&b>3)
        {
             printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}
