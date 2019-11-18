#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%01d",&a[i]);
        }
        int num=1;
        int last1=0;
        int last2=0;
        for(int i=1;i<=n;i++)
        {
            last2=i;
            if(a[i]==0)
            {
                if(k>i-num)
                {
                    k-=i-num;
                    num++;
                }
                else
                {
                    last1=i-k;
                    break;
                }

            }
        }
        cout<<num<<" "<<last1<<" "<<last2<<endl;
        for(int i=1;i<=n;i++)
        {
            if(i<num) printf("0");
            else if(i==last1) printf("0");
            else if(i<=last2) printf("1");
            else printf("%d",a[i]);
        }
        printf("\n");
    }
}
