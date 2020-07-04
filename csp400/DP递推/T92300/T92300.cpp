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
    int a;
    cin >> n;
    while (n--)
    {
        scanf("%d", &a);
        printf("%lld\n", ans[a - 1]);
    }

    return 0;
}