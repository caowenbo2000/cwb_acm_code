#include<bits/stdc++.h>
using namespace std;
char num[500005];
queue<char> num1;
queue<char> num2;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",num);
        int len=strlen(num);
        for(int i=0; num[i]; i++)
        {
            if(num[i]%2==1) num1.push(num[i]);
            else num2.push(num[i]);
        }
//        cout<<num1.front()<<" "<<num2.front()<<endl;
        for(int i=0; i<len; i++)
        {
            if(num1.size()==0)
            {
                printf("%c",num2.front());
                num2.pop();
            }
            else if(num2.size()==0)
            {
                printf("%c",num1.front());
                num1.pop();
            }
            else
            {
                if(num1.front()<num2.front())
                {
                    printf("%c",num1.front());
                    num1.pop();
                }
                else
                {
                    printf("%c",num2.front());
                    num2.pop();
                }
            }
        }
        printf("\n");
    }
}
