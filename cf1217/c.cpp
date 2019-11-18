#include<bits/stdc++.h>
using namespace std;
char s[200005];
int zero[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0;
        scanf("%s",s+1);
        int len=strlen(s+1);
        zero[1]=0;
        for(int i=2;i<=len;i++)
        {
            if(s[i-1]=='0')
            {
                zero[i]=zero[i-1]+1;
            }
            else
            {
                zero[i]=0;
            }
        }
        for(int i=1; i<=len; i++)
        {
            if(s[i]=='0') continue;
            long long tmp=0;
            for(int j=0;j<=30&&i+j<=len;j++)
            {
                tmp*=2;
                tmp+=s[i+j]-'0';
                if(zero[i]+j+1>=tmp)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
