#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int ans = -1;
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = 1;
        int tmp = i;
        while (tmp > 1 && i - tmp < x)
        {
            tmp--;
            if (a[i] >= a[tmp])
            {
                flag = 0;
            }
        }
        tmp = i;
        while (tmp < n && tmp - i < y)
        {
            tmp++;
            if (a[i] >= a[tmp])
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
}