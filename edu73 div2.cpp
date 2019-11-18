#include<bits/stdc++.h>
using namespace std;
int power[32];
int main()
{
//    s
//    t
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(power,0,sizeof(power));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            long long tmp;
            int cnt=-1;
            scanf("%I64d",&tmp);
            while(tmp)
            {
                tmp=tmp>>1;
                cnt++;
            }
            power[cnt]++;
        }
        for(int i=0;i<11;i++)
        {
            power[i+1]+=power[i]/2;
        }
        if(power[11])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
