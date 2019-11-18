#include<bits/stdc++.h>
using namespace std;
int vis[30];
char s[1000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%s",s);
        int n=strlen(s);
        int pos=1;
        for(int i=1;s[i];i++)
        {
            if(s[i]==s[i-1])
            {
                pos++;
            }
            else
            {
                if(pos%2==1)
                {
                    vis[s[i-1]-'a']=1;
                }
                pos=1;
            }
        }
        if(pos%2==1)
        {
            vis[s[n-1]-'a']=1;
        }
        for(int i=0;i<26;i++)
        {
            if(vis[i]==1)
                printf("%c",(char)i+'a');
        }
        printf("\n");
    }
}
