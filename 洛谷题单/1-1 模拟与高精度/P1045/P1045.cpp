#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn = 500;

int n;

struct bign
{
    int d[maxn << 1], len; //空间应大一倍，因为乘之后的结果位数会增加
    bign() : len(0) { memset(d, 0, sizeof(d)); }
} a, ans;

//两个bign进行相乘，高精度
bign mul(bign a, bign b)
{
    bign c;
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            c.d[i + j] += a.d[i] * b.d[j];
    for (int i = 0; i < 500; i++)
        if (c.d[i] > 9)
        {
            c.d[i + 1] += c.d[i] / 10;
            c.d[i] %= 10;
        }
    // c.len = a.len + b.len;
    // while (c.len >= 2 && c.d[c.len - 1] == 0)
    //     c.len--;
    return c;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    int len = n * log10(2.0) + 1;
    cout << len << endl;
    ans.d[0] = 1;
    a.d[0] = 2;
    while (n)
    {
        if (n & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    ans.d[0] -= 1;
    for (int i = 499, j = 0; i >= 0; i--, j++)
    {
        if (j && j % 50 == 0)
            printf("\n");
        printf("%d", ans.d[i]);
    }

    return 0;
}