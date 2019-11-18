#include<bits/stdc++.h>
using namespace std;
char s1[55];
char s2[55];
int vis[50];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<pair<int,int> >ans;
        memset(vis,0,sizeof(vis));
        int n;
        scanf("%d",&n);
        scanf("%s%s",s1,s2);
        for(int i=0; i<n; i++)
        {
            vis[s1[i]-'a']++;
            vis[s2[i]-'a']++;
        }
        int flag=0;
        for(int i=0; i<26; i++)
        {
            if(vis[i]%2==1)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(int i=0; i<n; i++)
        {
            if(s1[i]==s2[i]) continue;
            else
            {
                int flag1=0;
                for(int j=i+1; j<n; j++)
                {
                    if(s1[i]==s1[j])
                    {
                        swap(s2[i],s1[j]);
                        ans.push_back(make_pair(j+1,i+1));
                        flag1=1;
                        break;
                    }
                }
                if(flag1==0)
                {
                    for(int j=i+1; j<n; j++)
                    {
                        if(s1[i]==s2[j])
                        {
                            swap(s2[j],s1[n-1]);
                            swap(s1[n-1],s2[i]);
                            ans.push_back(make_pair(n,j+1));
                            ans.push_back(make_pair(n,i+1));
                            break;
                        }
                    }
                }
            }

        }
        printf("%d\n",ans.size());
        for(int i=0; i<ans.size(); i++)
        {
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
}
