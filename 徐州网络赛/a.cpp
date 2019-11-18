#include<bits/stdc++.h>
using namespace std;
int ans[500005];
struct node
{
    int num;
    int id;
}a[500005],b[500005];
int cmp(node p,node q)
{
    return p.num<q.num;
}
int main()
{
    memset(ans,-1,sizeof(ans));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].num);
        a[i].id=i;
        b[i]=a[i];
    }
    sort(b+1,b+1+n,cmp);
    int pos=1;
    for(int i=n;i>=1;i--)
    {
        while(b[pos].num+m<=a[i].num&&pos<=n)
        {
            //cout<<pos<<endl;
            if(i-1-b[pos].id<0) ;
            else ans[b[pos].id]=i-1-b[pos].id;
            pos++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d%s",ans[i],i==n?"\n":" ");
    }
    return 0;
}
