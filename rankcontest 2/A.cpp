#include <bits/stdc++.h>
using namespace std;
pair<double,double> p[1005];
int father[1005];
struct node
{
	double dis;
	int x;
	int y;
}edge[1000005];
int fin(int x)
{
	if(x==father[x]) return x;
	else return father[x]=fin(father[x]) ;
}
int cmp(node p,node q)
{
	return p.dis<q.dis;
}
int main()
{
	int n,e,c;
	scanf("%d%d%d",&n,&e,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&p[i].first,&p[i].second);
	}
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=2;i<=e;i++)
	{
		father[i]=fin(1);
	}
	for(int i=1;i<=c;i++)
	{
		int tmp1,tmp2;
		scanf("%d%d",&tmp1,&tmp2);
		father[fin(tmp1)]=fin(tmp2);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{	
			cnt++;
			edge[cnt].x=i;
			edge[cnt].y=j;
			edge[cnt].dis=sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second));
		}
	}
	double ans=0;
	sort(edge+1,edge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int tmp1=edge[i].x;
		int tmp2=edge[i].y;
		if(fin(tmp1)!=fin(tmp2))
		{
			father[fin(tmp1)]=fin(tmp2);
			ans+=edge[i].dis;
		}
	}
	printf("%.6lf\n",ans);
	return 0;
 } 
