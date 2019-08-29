#include <bits/stdc++.h>
using namespace std;
string s;
int len;
set<string>ss;
int l,r,mid;
bool check(int x){
    ss.clear();
    map<unsigned long long,int>mp;
    int f=0;
    unsigned long long h=0;
    unsigned long long p=1;
    for(int i=x-1;i>=0;--i){
        h+=(s[i]-'a')*p;
        p*=31;
    }
    p/=31;
    mp[h]++;
    for(int i=1;i+x<=len;++i){
        h=(h-((s[i-1]-'a')*p))*31+(s[i+x-1]-'a');
        if(mp[h]==1){
//            cout<<tmp<<endl;
            string tmp=s.substr(i,x);
            ss.insert(tmp);
            f=1;
        }
        mp[h]++;
    }
    return f;
}
int bis(){
    while(l<=r){
//        cout<<l<<" "<<r<<endl;
        mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    len=s.length();
    l=1;
    r=len-1;
    bis();
    string ans="{";
    check(l);
    string tmp=*ss.begin();
    if(tmp.size()>=ans.size())
    ans=min(ans,*ss.begin());
    check(r);
    tmp=*ss.begin();
    if(tmp.size()>=ans.size())
    ans=min(ans,*ss.begin());
    check(mid);
    tmp=*ss.begin();
    if(tmp.size()>=ans.size())
    ans=min(ans,*ss.begin());
    //cout<<l<<endl;
    cout<<ans<<endl;
    //cout<<ss.size()<<endl;
	return 0;
 }
 /**
 abcefgabc
 abcbabcba
 aaaa
 bbcaadbbeaa
 */
