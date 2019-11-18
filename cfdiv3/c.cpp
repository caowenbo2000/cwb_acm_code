#include<bits/stdc++.h>
using namespace std;
int num[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(num,0,sizeof(num));
        long long n;
        int len=0;
        scanf("%lld",&n);
        long long tmp=n;
        while(tmp)
        {
            ++len;
            num[len]=tmp%3;
            //cout<<num[len];
            tmp/=3;
        }
        //cout<<endl;
        int flag=0;
        int pos=0;
        for(int i=1;i<=len+1;i++)
        {
            if(num[i]==2) pos=i;
        }
        if(pos==0)
        {
            printf("%lld\n",n);
            continue;
        }
        for(int i=1;i<=len+1;i++)
        {
            if(i<=pos) num[i]=0;
            else
            {
                if(flag==0&&num[i]==0)
                {
                    num[i]=1;
                    flag=1;
                }
                else if(flag==0)
                {
                    num[i]=0;
                }
            }
        }
        long long ans=0;
        long long power=1;
        for(int i=1;i<=len+1;i++)
        {
           // cout<<num[i];
            ans+=power*num[i];
            power*=3;
        }
        printf("%lld\n",ans);
    }
}
