#include <bits/stdc++.h>
using namespace std;
string s;
string ans="{";
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
        p*=27;
        h+=(s[i]-'a')*p;
    }
    //cout<<0llu-1<<endl;
    mp[h]++;
    for(int i=1;i+x<=len;++i){
        h=(h-((s[i-1]-'a')*p))*27+(s[i+x-1]-'a')*27;
        if(mp[h]==1){
//            cout<<tmp<<endl;
            string tmp=s.substr(i,x);
            ss.insert(tmp);f=1;
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
    check(r);
    //cout<<l<<endl;
    cout<<*ss.begin()<<endl;
    //cout<<ss.size()<<endl;
	return 0;
 }
 /**
 abcefgabc
 abcbabcba
 aaaa
 bbcaadbbeaa
 */
