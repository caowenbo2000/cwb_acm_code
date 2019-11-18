#include<bits/stdc++.h>
using namespace std;
//RPS R>S S>P P>R
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[105];
        char ans[105];
        int win=0;
        int n;
        scanf("%d",&n);
        int r1,p1,s1;
        int r2=0,p2=0,s2=0;
        scanf("%d%d%d",&r1,&p1,&s1);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='P') p2++;
            if(s[i]=='R') r2++;
            if(s[i]=='S') s2++;
        }
        win=min(p1,r2)+min(r1,s2)+min(s1,p2);
        int nump=p1-min(p1,r2);
        int numr=r1-min(r1,s2);
        int nums=s1-min(s1,p2);
        int winp=min(p1,r2);
        int winr=min(r1,s2);
        int wins=min(s1,p2);
        if(win>=(n+1)/2)
        {
            printf("YES\n");
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='P')
                {
                    if(wins) wins--,printf("S");
                    else if(numr) numr--,printf("R");
                    else nump--,printf("P");
                }
                if(s[i]=='R')
                {
                    if(winp) winp--,printf("P");
                    else if(numr) numr--,printf("R");
                    else nums--,printf("S");
                }
                if(s[i]=='S')
                {
                    if(winr) winr--,printf("R");
                    else if(nums) nums--,printf("S");
                    else nump--,printf("P");
                }
            }
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }

}
