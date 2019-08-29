#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const long long mod=9901;
vector<pair<long long,long long> > ve;
long long quick_pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2==1) ans=(ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}
long long inv(long long b)
{
    return quick_pow(b,mod-2);
}
int main()
{
    long long a,b;
    cin>>a>>b;
    if(a==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    long long tmp=a;
    for(long long  i=2;i*i<=a;i++)
    {
        long long num=0;
        while(tmp%i==0)
        {
            tmp/=i;
            num++;
        }
        if(num) ve.push_back(make_pair(i,num));
    }
    if(tmp!=1) ve.push_back(make_pair(tmp,1));
    long long ans=1;
    for(int i=0;i<ve.size(); i++)
    {
        long long tmp;
        long long p=ve[i].second;
        long long q=ve[i].first;
        //cout<<p<<" "<<q<<endl;
        tmp=(quick_pow(q,(p*b+1)%mod) + 9900)%mod*inv(q-1)%mod ;
        //cout<<tmp<<endl;
        ans=(ans*tmp)%mod;
    }
    cout<<ans<<endl;
}