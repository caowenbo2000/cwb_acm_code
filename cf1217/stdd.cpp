#include<bits/stdc++.h>
using namespace std;
vector<int>ve[5005];
int n,m;
int IN[5005];
int tuopu()
{
    queue<int>q;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(IN[i]==0)
        {
            q.push(i);
            ans++;
        }
    }
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(auto v:ve[u])
        {
            IN[v]--;
            if(IN[v]==0)
            {
                q.push(v);
                ans++;
            }
        }
    }
    return ans==n;
}
int tmp1[5005];
int tmp2[5005];
int main()
{
    scanf("%d%d",&n,&m);
    memset(IN,0,sizeof(IN));
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&tmp1[i],&tmp2[i]);
        ve[tmp1[i]].push_back(tmp2[i]);
        IN[tmp2[i]]++;
    }
    if(tuopu())
    {
        printf("1\n");
        for(int i=1; i<=m; i++)
        {
            printf("1%s",i==m?"\n":" ");
        }
    }
    else
    {
        printf("2\n");
        for(int i=1; i<=m; i++)
        {
            if(tmp1[i]>tmp2[i])
            {
                printf("1%s",i==m?"\n":" ");
            }
            else
            {
                printf("2%s",i==m?"\n":" ");
            }
        }
    }

    return 0;
}
