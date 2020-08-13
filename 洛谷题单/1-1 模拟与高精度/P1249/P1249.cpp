#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 2000;

int n;
struct bign
{
    int d[maxn << 1], len; //空间应大一倍，因为乘之后的结果位数会增加
    bign() : len(0) { memset(d, 0, sizeof(d)); }
};

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

void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
        putchar(a.d[i] + '0');
    // printf("%d", a.d[i]);
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    int i, sum = 0;
    for (i = 2; i < 10000; i++)
    {
        sum += i;
        if (sum > n)
            break;
    }
    int begin = 2, no_mul;
    if (sum - n > 1)
    {
        no_mul = sum - n;
    }
    else
    {
        begin = 3;
        no_mul = i;
        i++;
    }
    bign a;
    a.len = 1;
    a.d[0] = 1;
    for (int j = begin; j <= i; j++)
    {
        if (j != no_mul)
        {
            cout << j << " ";
            a = mul(a, j);
        }
    }
    cout << endl;
    print(a);
    cout << endl;
    return 0;
}