#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
struct bign
{
    int d[3000], len;
    bign() : len(0) { memset(d, 0, sizeof(d)); }
};

//将字符串转换为bign
bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
        a.d[i] = str[a.len - i - 1] - '0';
    return a;
}

//高精度乘法
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

//输出bign
void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
        putchar(a.d[i] + '0');
    // printf("%d", a.d[i]);
}

int main()
{
    freopen("in.txt", "r", stdin);
    int t, a;
    cin >> t;
    while (t--)
    {
        cin >> n >> a;
        bign fact;
        fact.len = 1;
        fact.d[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact = mul(fact, i);
        }
        int ans = 0;
        for (int i = 0; i < fact.len; i++)
            if (fact.d[i] == a)
                ans++;
        printf("%d\n", ans);
    }

    return 0;
}