#include <bits/stdc++.h>
using namespace std;
string s;
string e;
int vis[2000000];
int ans = -1;
int so(string tmp)
{
	long long num=1;
	long long ans=0;
	for(int i=0;i<=7;i++)
	{
		ans+=num*(tmp[i]-'A');
		num*=6;
	}
	return ans;
}
string fso(int x)
{
	//cout<<x;
	string tmp="";
	while(x)
	{
		tmp+='A'+x%6;
		x/=6;
	}
	while(tmp.size()<8)
	{
		tmp+='A';
	}
	//cout<<tmp<<endl;
	return tmp;
}
queue<pair<int, int>> q;
void bfs()
{
	q.push(make_pair(so(s), 0));
	vis[so(s)] = 1;
	while (q.size())
	{
		int tmp4 = q.front().first;
		int tmp2 = q.front().second;
		string tmp1=fso(tmp4);
		string tmp3=tmp1;
		q.pop();
		for (int i = 0; i <= 7; i++)
		{
			tmp1=tmp3;
			if (tmp1[i] == 'A')
			{
				if (i - 1 >= 0)
				{
					tmp1[i - 1] = tmp1[i - 1] + 1;
					if (tmp1[i - 1] == 'G')
						tmp1[i - 1] = 'A';
				}
				if (i + 1 <= 7)
				{
					tmp1[i + 1] = tmp1[i + 1] + 1;
					if (tmp1[i + 1] == 'G')
						tmp1[i + 1] = 'A';
				}
			}
			if (tmp1[i] == 'B')
			{
				if (i != 0 && i != 7)
				{
					tmp1[i + 1] = tmp1[i - 1];
				}
			}
			if (tmp1[i] == 'C')
			{
				tmp1[7 - i] = tmp1[7 - i] + 1;
				if (tmp1[7 - i ] == 'G')
					tmp1[7 - i] = 'A';
			}
			if (tmp1[i] == 'D')
			{
				if (i != 0 && i != 7)
				{
					if (i <= 3)
					{
						for (int j = 0; j < i; j++)
						{
							tmp1[j] = tmp1[j] + 1;
							if (tmp1[j] == 'G')
								tmp1[j] = 'A';
						}
					}
					else
					{
						for (int j = i + 1; j <= 7; j++)
						{
							tmp1[j] = tmp1[j] + 1;
							if (tmp1[j] == 'G')
								tmp1[j] = 'A';
						}
					}
				}
			}
			if (tmp1[i] == 'E')
			{
				if (i != 0 && i != 7)
				{
					if (i >= 4)
					{
						int j = 7;
						tmp1[j] = tmp1[j] + 1;
						if (tmp1[j] == 'G')
							tmp1[j] = 'A';
						j = i - (7 - i);
						tmp1[j] = tmp1[j] + 1;
						if (tmp1[j] == 'G')
							tmp1[j] = 'A';
					}
					else 
					{
						int j = 0;
						tmp1[j] = tmp1[j] + 1;
						if (tmp1[j] == 'G')
							tmp1[j] = 'A';
						j = i + (i);
						tmp1[j] = tmp1[j] + 1;
						if (tmp1[j] == 'G')
							tmp1[j] = 'A';
					}
				}
			}
			if (tmp1[i] == 'F')
			{
				if (i % 2 == 0)
				{
					int j = (i + 10) / 2-1;
					tmp1[j] = tmp1[j] + 1;
					if (tmp1[j] == 'G')
						tmp1[j] = 'A';
				}
				else
				{
					int j = (i + 1) / 2-1;
					tmp1[j] = tmp1[j] + 1;
					if (tmp1[j] == 'G')
						tmp1[j] = 'A';
				}
			}
			tmp4=so(tmp1);
			if(tmp1==e)
			{
				ans=tmp2+1;
				return ;
			}
			//cout<<tmp4<<endl;
			if (vis[tmp4] == 0)
			{
				vis[tmp4] = 1;
				q.push(make_pair(tmp4, tmp2 + 1));
				//cout<<tmp1<<endl;
			}
		}
	}
}
int main()
{
	cin >> s;
	cin >> e;
	if(s==e)
	{
	cout<<"0"<<endl;
	return 0;
	}
	bfs();
	cout << ans << endl;
	return 0;
}
/*
ABCDEFCD
BCEDEFCD

DCDAFCBA
ECEABCCC

ABCDEFCD
ABCDEFCD

ACFEFBEB
EDBFEFDE

 */