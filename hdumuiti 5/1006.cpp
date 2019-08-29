#include<bits/stdc++.h>
using namespace std;
struct node
{
    vector<int> ve1;
    vector<int> ve2;
    friend bool operator < (const node &p,const node &q)
    {
        return p.ve2<q.ve2;
    } 
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        if(n<=9)
        {
            dfs();
        }
        else 
        {
            
        }
    }
}