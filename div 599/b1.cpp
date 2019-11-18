#include<bits/stdc++.h>
using namespace std;
char s1[10005];
char s2[10005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s%s",s1,s2);
        int cnt=0;
        int pos1=0;
        int pos2=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt==1) pos1=i;
                if(cnt==2) pos2=i;
            }
        }
        if(cnt==0) printf("Yes\n");
        else if(cnt==1)
        {
            char tmp=s1[pos1];
            s1[pos1]=s2[pos1];
            s2[pos1]=tmp;
            if(strcmp(s1,s2)==0)
            {
                printf("Yes\n");
            }
            else
            {
            printf("No\n");
            }
        }
        else if(cnt==2)
        {
            char tmp=s1[pos1];
            s1[pos1]=s2[pos2];
            s2[pos2]=tmp;
            if(strcmp(s1,s2)==0)
            {
                printf("Yes\n");
            }
            else
            {
            printf("No\n");
            }
        }
        else
        {
            printf("No\n");
        }
    }
}
