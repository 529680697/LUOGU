#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
    int l, r;
} no[1005];

struct bign
{
    int d[5000], len; //空间应大一倍，因为乘之后的结果位数会增加
    bign() : len(0) { memset(d, 0, sizeof(d)); }
};

int n;

bool cmp(node a, node b)
{
    return a.l * a.r < b.l * b.r;
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

//高精度除法，其中一个为int
bign div(bign a, int b, int &r)
{
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.d[i];
        if (r < b)
            c.d[i] = 0;
        else
        {
            c.d[i] = r / b;
            r %= b;
        }
    }
    while (c.len >= 2 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}

//输出bign
void print(bign &a)
{
    for (int i = a.len - 1; i >= 0; i--)
        // putchar(a.d[i] + '0');
        // printf("%d", a.d[i]);
        cout << a.d[i];
}

bign _max(bign a, bign b)
{
    if (a.len > b.len)
        return a;
    else if (a.len < b.len)
        return b;
    for (int i = a.len - 1; i >= 0; i--)
    {
        if (a.d[i] > b.d[i])
            return a;
        else if (a.d[i] < b.d[i])
            return b;
    }
    return a;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    int flag = 0;
    for (int i = 0; i <= n; i++)
        cin >> no[i].l >> no[i].r;
    sort(no + 1, no + n + 1, cmp);
    bign a, c, ans;
    int r;
    a.len = 1, a.d[0] = 1;
    ans.len = 1;
    for (int i = 0; i < n; i++)
    {
        r = 0;
        a = mul(a, no[i].l);
        c = div(a, no[i + 1].r, r);
        ans = _max(ans, c);
    }
    print(ans);
    cout << endl;

    return 0;
}