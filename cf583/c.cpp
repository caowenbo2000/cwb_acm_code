#include<bits/stdc++.h>
using namespace std;
char s[200005];
stack<char> st;
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int cnt1=0;
    int cnt2=0;
    for(int i=1;s[i];i++)
    {
        if(s[i]=='(') cnt1++;
        else cnt2++;
        if(s[i]==')'&&st.size()&&st.top()=='(')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    if(st.size()==2&&cnt1==cnt2||st.size()==0)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
}
