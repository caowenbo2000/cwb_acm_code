#include<bits/stdc++.h>
using namespace std;
char s[300005];
vector<int>ve;
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int pos=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]==s[i-1])
        {
            pos++;
        }
        else
        {
            ve.push_back(pos);
            pos=1;
        }
        if(i==n) ve.push_back(pos);
    }
    long long ans=n*(n-1)/2;
    if(ve.size()>=2)
    {
        for(int i=0;i<ve.size();i++)
        {
            if(i==0||i==ve.size()-1) ans-=ve[i];
            else ans-=ve[i]*2;
        }
        ans+=ve.size()-1;
    }
    printf("%d\n",ans);
}
