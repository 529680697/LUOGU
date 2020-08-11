#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 2010;

struct bign
{
    int d[maxn << 1], len; //空间应大一倍，因为乘之后的结果位数会增加
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
        putchar(a.d[i] + '0');
    // printf("%d", a.d[i]);
}

int main()
{
    char a[maxn], b[maxn];
    freopen("in.txt", "r", stdin);
    scanf("%s%s", a, b);
    print(mul(change(a), change(b)));
    printf("\n");
    return 0;
}