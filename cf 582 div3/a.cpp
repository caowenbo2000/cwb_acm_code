#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int cnt1=0;
    int cnt2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp%2==1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    printf("%d\n",min(cnt1,cnt2));
}
