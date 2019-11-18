#include<bits/stdc++.h>
using namespace std;
char s[10005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int cnt1=0;
        int cnt2=0;
        int n;
        scanf("%d",&n);
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(strlen(s)%2==1) flag=1;
            for(int j=0;s[j];j++)
            {
                if(s[j]=='0') cnt2++;
                else cnt1++;
            }
        }
        if(flag==0&&cnt1%2==1)
        {
            printf("%d\n",n-1);
        }
        else
        {
            printf("%d\n",n);
        }
    }
}
