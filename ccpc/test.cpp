#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans=0;
    for(int i=1;i<=10000;i++)
    {
        ans+=(double)(i*(i+1)/2)/pow(2,i);
    }
    printf("%f\n",ans);
}
