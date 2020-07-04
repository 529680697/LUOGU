#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long ans[55];

int main()
{
    ans[1] = 1, ans[2] = 2;
    for (int i = 3; i < 55; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    int a, b;
    cin >> n;
    while (n--)
    {
        scanf("%d%d", &a, &b);
        printf("%lld\n", ans[b - a]);
    }

    return 0;
}