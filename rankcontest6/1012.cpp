//writen by cwb
#include<bits/stdc++.h>
using namespace std;
//pair<int,int> p[100005];
//priority_queue <pair<int,int> >q;
//int vis[100005];
//long long su,el;
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        su=0;
//        el=0;
//        memset(vis,0,sizeof(vis));
//        int n;
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&p[i].first);
//            p[i].second=i;
//            if(i*2<=n) vis[i]++;
//            if(i*2+1<=n) vis[i]++;
//        }
//        sort(p+1,p+1+n);
//        for(int i=1;i<=n;i++)
//        {
//            if(vis[i]==0) q.push(p[i]);
//        }
//        int cnt=0;
//        while(q.size())
//        {
//            cnt++;
//            if(cnt%2==1) su+=q.top().first;
//            else el+=q.top().first;
//            vis[q.top().second/2]--;
//            if(vis[q.top().second/2]==0)
//            {
//                q.push(p[q.top().second/2]);
//            }
//            q.pop();
//        }
//        printf("%lld %lld\n",su,el);
//    }
//}
int main()
{
    cout<<(6^5)<<endl;
}
