#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        int cnt=0;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a!=0) cnt++;
        if(b!=0) cnt++;
        if(c!=0) cnt++;
        if(d!=0) cnt++;
        if(cnt==0)
        {
            printf("Typically Otaku\n");
        }
        else if(cnt==1)
        {
            printf("Eye-opener\n");
        }
        else if(cnt==2)
        {
            printf("Young Traveller\n");
        }
        else if(cnt==3)
        {
            printf("Excellent Traveller\n");
        }
        else if(cnt==4)
        {
            printf("Contemporary Xu Xiake\n");
        }
    }
    return 0;
}
