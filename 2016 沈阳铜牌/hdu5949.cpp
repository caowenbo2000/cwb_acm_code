#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[15];
        scanf("%s",&s);
        int ans=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='O') ans+=16;
            if(s[i]=='C') ans+=12;
            if(s[i]=='H') ans+=1;
        }
        printf("%d\n",ans);
    }
}
