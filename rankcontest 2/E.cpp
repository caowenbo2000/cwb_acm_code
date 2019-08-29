#include <bits/stdc++.h>
using namespace std;
const int maxn=10000009;
bool is_prime[maxn]={0};
int prime[maxn],mu[maxn],prime_cnt;
void Mobius()
{
	prime_cnt=0;
	mu[1]=1;
	is_prime[1]=1;
	for (int i=2;i<maxn;i++)
	{
		if (!is_prime[i])
		{
			prime[prime_cnt++]=i;
			mu[i]=-1;
		}
		for (int j=0;j<prime_cnt&&1ll*i*prime[j]<maxn;j++)
		{
			is_prime[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			else mu[i*prime[j]]=-mu[i];
		}
	}
}

int main()
{
	Mobius();
	long long a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long ans=0;
	for (int i=1;i<=min(b,d);i++)
	{
		ans+=mu[i]*(b/i)*(d/i);
	}
	for (int i=1;i<=min(a-1,d);i++)
	{
		ans-=mu[i]*((a-1)/i)*(d/i);
	}
	for (int i=1;i<=min(b,c-1);i++)
	{
		ans-=mu[i]*(b/i)*((c-1)/i);
	}
	for (int i=1;i<=min(a-1,c-1);i++)
	{
		ans+=mu[i]*((a-1)/i)*((c-1)/i);
	}
	printf("%lld\n",ans);
	return 0;
 } 
