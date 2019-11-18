#include<bits/stdc++.h>
using namespace std;
int vis1[400];
int vis2[400];
char s1[105];
char s2[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        int n;
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        for(int i=0;s1[i];i++)
        {
            vis1[s1[i]]++;
        }
        for(int i=0;s2[i];i++)
        {
            vis2[s2[i]]++;
        }
        int flag=0;
        for(int i=1;i<=300;i++)
        {
            if(vis1[i]&&vis2[i]) flag=1;
        }
        if(flag==1)
        printf("YES\n");
        else
        printf("NO\n");
    }
}
