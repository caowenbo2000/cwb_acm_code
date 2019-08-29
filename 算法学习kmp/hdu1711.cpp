#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int b[1000005];
int nxt[1000005];
void get_nxt()
{
    int j,k;
    nxt[0]=-1;
    k=-1;
    j=0;
    while(j<m-1)
    {
        if(k==-1||b[j]==b[k])
        {
            k++;
            j++;
            nxt[j]=k;
        }
        else
        {
            k=nxt[k];
        }
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        get_nxt();
        for(int i=0;i<m;i++) cout<<nxt[i];
       cout<<endl;
        int i=0,j=0;
        int ans=-1;
        while(i<n&&j<m)
        {
            if(j==-1||a[i]==b[j])
            {
                j++;
                i++;
            }
            else
            {
                j=nxt[j];
            }
            if(j==m)
            {
                ans=i-m+1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
