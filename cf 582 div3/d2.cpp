#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >mp;
int a[200005];
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        while(a[i])
        {

            mp[a[i]].push_back(cnt);
            a[i]/=2;
            cnt++;
        }
        mp[0].push_back(cnt);
    }
    int ans=1e9;
    int tmp=0;
    for(map<int,vector<int> >::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second.size()>=k)
        {
            sort(it->second.begin(),it->second.end());
            tmp=0;
            for(int i=0; i<k; i++)
            {
                tmp+=it->second[i];
            }
            ans=min(ans,tmp);
        }
    }
    printf("%d\n",ans);
}
