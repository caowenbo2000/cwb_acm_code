#include<bits/stdc++.h>
using namespace std;
using PI=pair<int,int>;
int a[200005];
bool cmp(PI p,PI q)
{
    if(p.first==q.first)
    {
        return p.second>q.second;
    }
    return p.first>q.first;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        vector<PI>ve1;
        vector<PI>ve2;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            PI tmp;
            scanf("%d%d",&tmp.first,&tmp.second);
            ve1.push_back(tmp);
        }
        sort(ve1.begin(),ve1.end(),cmp);
        int MAX=0;
        for(int i=0;i<m;i++)
        {
            if(ve1[i].second>MAX)
            {
                ve2.push_back(ve1[i]);
                MAX=ve1[i].second;
            }
        }
        sort(ve2.begin(),ve2.end());
        int ans=1;
        int num=0;
        int cur=0;
        //cout<<":"<<ve2.size()<<endl;
        for(int i=1;i<=n;i++)
        {
            num++;
            int pos=lower_bound(ve2.begin(),ve2.end(),make_pair(a[i],0))-ve2.begin();
            cur=max(pos,cur);
            if(pos==ve2.size()) {ans=-1;break;}
            else
            {
                if(ve2[cur].second<num) ans++,num=1,cur=lower_bound(ve2.begin(),ve2.end(),make_pair(a[i],0))-ve2.begin();
            }
            //cout<<pos<<" "<<i<<":"<<ans<<endl;
        }
        printf("%d\n",ans);
    }
}
