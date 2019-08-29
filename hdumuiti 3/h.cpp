#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int di[9],a,l,r,ans=0;;
	scanf("%d%d",&l,&r);
	for (int i=l;i<=r;i++)
	{
		bool flag=1;
		a=i;
		map <int,int> mp;
		for (int j=0;j<6;j++)
		{
			di[j]=a%10;
			mp[di[j]]++;
			a/=10;
		}
		if (mp.size()<6||mp[0]) continue;
		for (int j=0;j<6;j++)
		{
			if (i%di[j])
			{
				flag=0;
				break;
			}
		}
		if (flag) ans++;
	}
	printf("%d\n",ans);
	return 0;
 } 
