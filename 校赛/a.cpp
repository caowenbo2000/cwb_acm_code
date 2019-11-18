#include<bits/stdc++.h>
using namespace std;
char s[10000005];
char s1[10000005];
int nxt[10000005];
int n;
void get_nxt()
{
    int i=0;
    int k=-1;
    nxt[0]=-1;
    while(i<n)
    {
        if(k==-1||s[i]==s[k])
        {
            i++;
            k++;
            nxt[i]=k;
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
    long long a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        scanf("%s",s1);
        n=strlen(s1);
        for(int i=0;i<n;i++)
        {
            s[n-1-i]=s1[i];
        }
//        for(int i=0;i<n;i++)
        get_nxt();
//        for(int i=1;i<=n;i++)
//        {
//            printf("%d",nxt[i]);
//        }
//        cout<<endl;
        long long ans=-1e9;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='.') break; //Ñ­»·½Ú n-nxt[n]
            ans=max(ans,a*i-b*(i-nxt[i]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
