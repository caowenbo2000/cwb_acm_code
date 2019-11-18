#include<bits/stdc++.h>
using namespace std;
signed main()
{
    freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
//        cout<<i<<endl;
        int ans=0;
        for(int j=1;j<=i;j++)
        {
            int flag=0;
            for(int k=1;k<j-1;k++)
            {
                if(i%(j-k)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) ans++;
        }
        printf("%d %d\n",i,ans);
    }
}
