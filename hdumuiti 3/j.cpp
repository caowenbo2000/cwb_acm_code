#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        deque<pair<long long, long long>> q; //first为值 second为下标
        long long s = 1;
        long long sum = 1;
        for (int i = 1; i <= n; i++)
        {
            s = (s * a) % b;
            while (q.size() || q.back().first > s)
                q.pop_back();
            q.push_back(make_pair(s, i));
            while (i - q.front().second > a)
                q.pop_front();
            sum = (sum * q.back().first)%b ;
        }
        cout << sum << endl;
    }
}