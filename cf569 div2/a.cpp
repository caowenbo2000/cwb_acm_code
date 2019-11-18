#include<bits/stdc++.h>
using namespace std;
int main()
{
    //int t;
    //scanf("%d",&t);
    //while(t--)
    {
         int a,b;
         scanf("%d%d",&a,&b);
         if(a==b-1)
         {
             printf("%d %d\n",a,b);
         }
         else if(a==b)
         {
             printf("%d0 %d1\n",a,b);
         }
         else if(a==9&&b==1)
         {
             printf("9 10\n");
         }
         else
         {
             printf("-1\n");
         }
    }
}
