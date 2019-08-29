#include<bits/stdc++.h>
using namespace std;
char s[15];
char s1[15];
char s2[15];
int len;
void big()
{
    int flag=0;
    for(int i=1;i<len;i++)
    {
        char c=s1[i];
        int x=0;
        for(int j=i+1;j<=len;j++)
        {
            if(s1[i]<s1[j])
            {
                if(s1[j]>=c) x=j;
                c=max(c,s1[j]);
            }
        }
        if(c!=s1[i])
        {
            swap(s1[i],s1[x]);
            break;
        }
    }
}
void sma()
{
    int flag=0;
    for(int i=1;i<len;i++)
    {
        int x=0;
        char c=s2[i];
        for(int j=i+1;j<=len;j++)
        {

            if(s2[i]>s2[j])
            {
                if(s2[j]<=c) x=j;
                c=min(c,s1[j]);
            }
        }
        if(c!=s2[i])
        {
            swap(s2[i],s2[x]);
            break;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%s%d",s+1,&k);
        for(int i=1;s[i];i++) s1[i]=s[i],s2[i]=s[i];
        len=strlen(s+1);
        s1[len+1]='\0';
        s2[len+1]='\0';
        if(k>10) k=10;
        while(k--)
        {
            big();
            sma();
        }
        int flag=0;
        for(int i=1;i<=len;i++)
        {
            if(s2[i]!='0') flag=1;
            if(flag==0&&s2[i]=='0') continue;
            else printf("%c",s2[i]);
        }
        printf(" ");
        flag=0;
        for(int i=1;i<=len;i++)
        {
            if(s1[i]!='0') flag=1;
            if(flag==0&&s1[i]=='0') continue;
            else printf("%c",s1[i]);
        }
        printf("\n");
    }
}
