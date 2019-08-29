#include<cstdio>
#include<iostream>
#include<algorithm>
//Author: cwb 8/12/2019
using namespace std;
int a[100005];
int tmp[100005];
long long ans=0;
void mergesort(int s,int e)
{
    if(s==e) return ;
    int mid=(s+e)/2;
    mergesort(s,mid);
    mergesort(mid+1,e);
    int cur1=s,cur2=mid+1;
    for(int i=s; i<=e; i++)
    {
        if(cur1>mid) tmp[i]=a[cur2],cur2++;
        else if(cur2>e) tmp[i]=a[cur1],cur1++;
        else if(a[cur2]<a[cur1]) tmp[i]=a[cur2],ans+=mid-cur1+1,cur2++;
        else tmp[i]=a[cur1],cur1++;
    }
    //cout<<":";
    for(int i=s; i<=e; i++)
    {
        a[i]=tmp[i];
    }
    //cout<<endl;
}
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        ans=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        mergesort(1,n);
        long long x;
        x=max(0LL,ans-k);
        printf("%d\n",x);
    }

}
