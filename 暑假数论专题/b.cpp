#include<bits/stdc++.h>
using namespace std;
long long euler(long long n)  
{  
    long long ans=n;  
    for(int i=2;i*i<=n;i++){  
        if(n%i==0){  
            ans-=ans/i;  
            while(n%i==0){  
                n/=i;  
            }  
        }  
    }  
    if(n>1) ans-=ans/n;  
    return ans;  
}
long long quick_power(long long a,long b, long long c)
{
    long long ans=1;
    while(b)
    {
        if(b%2==1) ans=(ans*a)%c;
        b/=2;
        a=(a*a)%c;
    }
    return ans;
}
long long f(long long x)
{
    if(euler(x)==1)
    {
        return 2;
    }
    return quick_power(2,f(euler(x))%euler(x)+euler(x),x);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        //cout<<"n"<<n<<endl;
        printf("%lld\n",f(n)%n);
    }
    return 0;
}