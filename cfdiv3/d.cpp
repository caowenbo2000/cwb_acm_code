#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s;
    int e;
    int id;
}a[200005];
int cmp(node p,node q)
{
    return p.s<q.s;
}
vector<int> ans;
set<pair<int,int> > st;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int maxn,minn;
    pair<int,int>tmp;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].s,&a[i].e);
        maxn=max(maxn,a[i].e);
        minn=min(minn,a[i].s);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    int pos=1;
    for(int i=minn;i<=maxn;i++)
    {
        while(pos<=n&&a[pos].s<=i)
        {
            st.insert(make_pair(a[pos].e,a[pos].id));
            pos++;
        }
        while(st.size()&& st.begin()->first<i)
        {
            st.erase(st.begin());
        }
        while(st.size()>k)
        {
            tmp=*(--st.end());
            ans.push_back(tmp.second);
            st.erase(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto v:ans)
    {
        printf("%d ",v);
    }
    printf("\n");
}
