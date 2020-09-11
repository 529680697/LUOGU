// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int n, m, num[85];
bool vis[85][85];
struct bign
{
    int d[maxn << 1], len; //空间应大一倍，因为乘之后的结果位数会增加
    bign() : len(0) { memset(d, 0, sizeof(d)); }
    bool operator<(const bign &b) const
    {
        if (len == b.len)
        {
            for (int i = len - 1; i >= 0; i--)
                if (d[i] < b.d[i])
                    return true;
                else if (d[i] > b.d[i])
                    return false;
            return false;
        }
        else
            return len < b.len;
    }
} dp[85][85], ans, p[85];

//将字符串转换为bign
bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
        a.d[i] = str[a.len - i - 1] - '0';
    return a;
}

//两个bign进行相加，高精度
bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int tmp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry)
        c.d[c.len++] = carry;
    return c;
}

//高精度乘法，其中一个为int
bign mul(bign a, int b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++)
    {
        int tmp = a.d[i] * b + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

//两个bign进行相乘，高精度
bign mul(bign a, bign b)
{
    bign c;
    for (int i = 0; i < a.len; i++)
        for (int j = 0; j < b.len; j++)
            c.d[i + j] += a.d[i] * b.d[j];
    for (int i = 0; i < a.len + b.len; i++)
        if (c.d[i] > 9)
        {
            c.d[i + 1] += c.d[i] / 10;
            c.d[i] %= 10;
        }
    c.len = a.len + b.len;
    while (c.len >= 2 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}

//输出bign
void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
        // putchar(a.d[i] + '0');
        cout << a.d[i];
}

inline void init()
{
    p[0].len = 1, p[0].d[0] = 1;
    for (int i = 1; i < 85; i++)
        p[i] = mul(p[i - 1], 2);
}

bign dfs(int l, int r)
{
    if (vis[l][r])
        return dp[l][r];
    vis[l][r] = true;
    if (l == r)
        return dp[l][r] = mul(p[m - (r - l)], num[l]);
    bign ll = add(dfs(l + 1, r), mul(p[m - (r - l)], num[l]));
    bign rr = add(dfs(l, r - 1), mul(p[m - (r - l)], num[r]));
    if (ll < rr)
        return dp[l][r] = rr;
    else
        return dp[l][r] = ll;
}

inline void clear()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 85; i++)
        for (int j = 0; j < 85; j++)
            dp[i][j].len = 0;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cin.tie(nullptr);
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        clear();
        for (int j = 1; j <= m; j++)
            cin >> num[j];
        ans = add(ans, dfs(1, m));
    }
    print(ans);
    return 0;
}