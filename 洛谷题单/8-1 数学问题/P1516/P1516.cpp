// #include <iostream>
// #include <cstdio>
// #include <algorithm>

// using namespace std;
// typedef long long ll;
// const int inf = 0x3f3f3f3f;
// const int maxn = 1e5 + 5;

// ll x, y, m, n, l, v;

// int main()
// {
//     freopen("in", "r", stdin);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> x >> y >> m >> n >> l;
//     if (m > n)
//     {
//         v = m - n;
//         for (ll i = (x + v) % l, num = 1; i != x; i = (i + v) % l, num++)
//         {
//             if (i == y)
//             {
//                 cout << num << endl;
//                 return 0;
//             }
//         }
//         cout << "Impossible" << endl;
//     }
//     else if (n > m)
//     {
//         v = n - m;
//         for (ll i = (y + v) % l, num = 1; i != y; i = (i + v) % l, num++)
//         {
//             if (i == x)
//             {
//                 cout << num << endl;
//                 return 0;
//             }
//         }
//         cout << "Impossible" << endl;
//     }
//     else if (x != y)
//         cout << "Impossible" << endl;
//     else
//         cout << 0 << endl;
//     return 0;
// }

#include <cstdio>
#define LL long long
LL x, y, m, n, l, a, b, c, x0, y0, g, tmp;
void exgcd(LL a, LL b)
{
    if (!b)
    {
        x0 = 1;
        g = a;
        return;
    } //顺便求gcd
    exgcd(b, a % b);
    tmp = x0;
    x0 = y0;
    y0 = tmp - a / b * y0;
}
int main()
{
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
    a = n - m;
    b = l;
    c = x - y;
    if (a < 0)
        a = -a, c = -c; //处理a为负数情况
    exgcd(a, b);
    if (c % g)
        puts("Impossible");
    else
        printf("%lld\n", (c / g * x0 % (b / g) + b / g) % (b / g)); //求最小非负整数解
    return 0;
}