#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long ans[10005];

int main()
{
    ans[1] = 2, ans[2] = 7;
    for (int i = 3; i < 10001; i++)
    {
        ans[i] = ans[i - 1] + 4 * i - 3;
    }
    int a;
    cin >> n;
    while (n--)
    {
        scanf("%d", &a);
        printf("%lld\n", ans[a]);
    }

    return 0;
}