#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void Joes(int n,list<int> &number,int m)
{
    if(n < 1||m <1 )
        return ;
    list<int>::iterator current=number.begin();
    while(number.size()>0)
    {
        while(--m)
        {
            current++;
            if(current == number.end())
                current=number.begin();
        }
        m=*current;
        cout<<*current<<" ";
        list<int>::iterator next=++current;
        if(next == number.end())
            next=number.begin();
        --current;
        number.erase(current);
        current=next;
    }
}

int main()
{
    int len,m;
    list<int> number;
    cin>>len;
    int num;
    for(int i=0;i<len;i++)
    {
        cin>>num;
        number.push_back(num);
    }
    cin>>m;
    Joes(len,number,m);
    return 0;
}
