#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[maxn];
int main(){
    scanf("%s",s);
    int ans=0;
    for(int i=0;s[i];++i){
        int len=0;
        int tmp=0;
        while(i-len>=0&&s[i+len]&&s[i+len]==s[i-len]){
            tmp=tmp|(1<<(s[i+len]-'a'));
            len++;
            ans+=__builtin_popcount(tmp);
        }
        len=0;
        tmp=0;
        while(i-len>=0&&s[i+len+1]&&s[i+len+1]==s[i-len]){
            tmp=tmp|(1<<(s[i+len+1]-'a'));
            len++;
            ans+=__builtin_popcount(tmp);
        }
    }
    printf("%d\n",ans);
}
