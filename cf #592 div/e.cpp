#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int pos1=1;
    int pos2=n;
    long long ans=a[n]-a[1];
    while(pos1<pos2)
    {
        long long tmp=0;
        if(pos1-1<=n-pos2)
        {
            pos1++;
            tmp=min(1LL*a[pos1]-a[pos1-1],k/(pos1-1));
            ans-=tmp;
            k-=1LL*tmp*(pos1-1);
        }
        else
        {
            pos2--;
            tmp=min(1LL*a[pos2+1]-a[pos2],k/(n-pos2));
            ans-=tmp;
            k-=1LL*tmp*(n-pos2);
        }
//        cout<<tmp<<endl;
        //if(tmp==0) break;
    }
    printf("%lld\n",ans);
}
