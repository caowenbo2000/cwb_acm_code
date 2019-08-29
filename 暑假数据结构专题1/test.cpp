#include<ext/hash_map>
#include<iostream>
using namespace __gnu_cxx;
using namespace std;
int main()
{
    hash_map<int,int> mp;
    mp[2]=3;
    mp[-1]=1;
    //mp[2]=0;
    printf("%d %d\n",mp[-1],mp[2]);
    printf("%d",mp.size());
    for(auto V: mp)
    {
        cout<<V.first<<endl;
    }
}