#include<bits/stdc++.h>
using namespace std;
int len[10005];
int main()
{
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    int sum=0;
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&len[i]);
        sum+=len[i];
    }
    int num=n-sum;
    if(sum>(d-1)*(m+1))
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        for(int i=1; i<=m; i++)
        {
            int tmp=d-1;
            while(tmp&&num)
            {
                printf("0 ");
                num--;
                tmp--;
            }
            while(len[i])
            {
                printf("%d ",i);
                len[i]--;
            }
        }
        while(num)
        {
            printf("0 ");
            num--;
        }
    }
}
