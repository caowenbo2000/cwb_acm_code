#include<bits/stdc++.h>
using namespace std;
int viss[100];
int vist[100];
char s[200005];
char t[200005];
int n;
void solve()
{
    memset(viss,0,sizeof(viss));
    memset(vist,0,sizeof(vist));
    for(int i=1; s[i]; i++)
    {
        viss[s[i]-'a']++;
        vist[t[i]-'a']++;
    }
    for(int i=0; i<26; i++)
    {
        if(viss[i]!=vist[i])
        {
            printf("NO\n");
            return;
        }
    }
    for(int i=0; i<26; i++)
    {
        if(viss[i]>1)
        {
            printf("YES\n");
            return ;
        }
    }
    int cnt1=0;
    int cnt2=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(s[i]>s[j]) cnt1++;
            if(t[i]>t[j]) cnt2++;
        }
    }
    if(cnt1%2==cnt2%2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        solve();
    }
}
