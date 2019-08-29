#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,vis[199]= {0};
	char str[9];
	for (int i=0; i<5; i++)
		{
			scanf("%s",str);
			vis[str[0]]++;
		}
	int mmax=-1;
	for (int i=50; i<=57; i++)
		mmax=max(mmax,vis[i]);
	mmax=max(mmax,vis[65]);
	mmax=max(mmax,vis[84]);
	mmax=max(mmax,vis[81]);
	mmax=max(mmax,vis[75]);
	mmax=max(mmax,vis[74]);
	printf("%d\n",mmax);
	return 0;
}
