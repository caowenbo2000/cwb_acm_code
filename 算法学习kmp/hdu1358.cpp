#define LOCAL
#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int nxt[1000005];
int n;
void get_nxt()
{
    int i=0;
    int k=-1;
    nxt[0]=-1;
    while(i<n)
    {
        if(k==-1||s[k]==s[i])
        {
            k++;
            i++;
            nxt[i]=k;
        }
        else
        {
            k=nxt[k];
        }
    }
    return ;
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // LOCAL
    int cas=0;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        cas++;
        cout<<"Test case #"<<cas<<endl;
        scanf("%s",s);
        get_nxt();
        for(int i=2;i<=n;i++)
        {
            if(i%(i-nxt[i])==0)
            {
                if(nxt[i]!=0)
                //cout<<i<<" "<<i-nxt[i]<<" ";
                printf("%d %d\n",i,i/(i-nxt[i]));
            }
        }
        cout<<endl;
    }
}
