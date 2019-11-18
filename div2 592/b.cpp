#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int tmp;
        int MAX=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%01d",&tmp);
            if(tmp==1)
            {
                MAX=max(MAX,i);
                MAX=max(MAX,n-i+1);
            }
        }
        if(MAX==0)
        {
            printf("%d\n",n);
        }
        else
        {
            printf("%d\n",MAX*2);
        }
    }
}
