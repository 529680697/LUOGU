#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, a[5000005];
// priority_queue<int> q;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return f == 1 ? x : -x;
}

// int main()
// {
//     freopen("in.txt", "r", stdin);
//     n = read(), k = read();
//     for (int i = 0; i < n; i++)
//     {
//         a = read();
//         if (i <= k)
//             q.push(a);
//         else if (q.top() > a)
//             q.pop(), q.push(a);
//     }
//     printf("%d\n", q.top());
//     return 0;
// }

int main()
{
    // ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    n = read(), k = read();
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
    }
    nth_element(a, a + k, a + n);
    printf("%d\n", a[k]);
    return 0;
}