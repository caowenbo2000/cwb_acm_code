#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    int num;
    int col;
    friend bool operator < (node p,node q)
    {
        return p.num<q.num;
    }
}a[200005];
int dp[200005];
bool cmp(node p,node q)
{
    return p.id<q.id;
}
int main()
{
    vector<int>ve;
    memset(dp,0,sizeof(dp));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].num);
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    int MAX=0;
    int pos=0;
    for(int i=4;i<=n-2;i++)
    {
        for(int j=3;j<=5;j++)
        {
            if(i>j)
            {
                dp[i]=max(dp[i-j]+a[i].num-a[i-1].num,dp[i]);
            }
        }
        if(dp[i]>MAX)
        {
            MAX=dp[i];
            pos=i;
        }
    }
    while(pos>3)
    {
        int flag=0;
        for(int i=3;i<=5;i++)
        {
            if(dp[pos]-dp[pos-i]==a[pos].num-a[pos-1].num)
            {
                flag=1;
               ve.push_back(pos);
               pos=pos-i;
               break;
            }
        }
        if(flag==0) break;
    }
    sort(ve.begin(),ve.end());
    int tmp=1;
    int cur=0;
//    cout<<ve[0]<<" "<<ve[1]<<endl;
    for(int i=1;i<=n;i++)
    {
        if(cur>=ve.size()||i!=ve[cur]) a[i].col=tmp;
        else
        {
            cur++;
            tmp++;
            a[i].col=tmp;
        }
    }
    printf("%d %d\n",a[n].num-a[1].num-MAX,ve.size()+1);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i].col);
    }
}
