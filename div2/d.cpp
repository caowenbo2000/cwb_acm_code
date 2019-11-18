#include<bits/stdc++.h>
using namespace std;
long long a[7007];
long long b[7007];
vector<int> G[7007];
vector<int> GG[7007];
struct node
{
    int OUT;
    int id;
}c[7007];
int cmp(node p,node q)
{
    return p.OUT>q.OUT;
}
int vis[7007];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            for(int k=0;k<60;k++)
            {
                if(((a[i]>>k)&1==1)&&((a[j]>>k)&1==0))
                {
                    G[i].push_back(j);
                    GG[j].push_back(i);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        c[i].id=i;
        c[i].OUT=G[i].size();
    }
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)
    {
        if(int i=)
    }
}
