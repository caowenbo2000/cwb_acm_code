/* ***********************************************
Author        :CWb
Created Time  :2019年10月24日 星期四 19时55分50秒
File Name     :a.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

int len[105][10];
int dir[6][2]={2,3 ,3,2 , 1,3 ,3,1 ,1,2 ,2,1};
vector<int > G[605];
int dp[605];
int vis[605];
int dfs(int x)
{
    //cout<<x<<endl;
    if(dp[x]!=0) return dp[x];
    int MAX=0;
	for(auto v:G[x])
	{
		MAX=max(MAX,dfs(v));
	}
	dp[x]=MAX+len[x/6+1][(x%6+2)/2];
	return dp[x];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int n;
    int cas=0;
	while(~scanf("%d",&n))
	{
	    if(n==0) return 0;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n*6;i++) G[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&len[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int  j=1;j<=n;j++)
			{
				for(int l=0;l<6;l++)
				{
					for(int k=0;k<6;k++)
					{
						int tmp1=(i-1)*6+l;
						int tmp2=(j-1)*6+k;
						if(len[i][dir[l][0]]<len[j][dir[k][0]]&&len[i][dir[l][1]]<len[j][dir[k][1]])
						{
							G[tmp2].push_back(tmp1);
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n*6-1;i++)
		{
		    ans=max(ans,dfs(i));
		}
		cas++;
		printf("Case %d: maximum height = %d\n",cas,ans);
	}
    return 0;
}
/*
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
*/
