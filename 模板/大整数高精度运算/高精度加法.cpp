#include <cstdio>
#include <cstring>

struct bign
{
    int d[1000], len;
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

//输出bign
void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
        putchar(a.d[i] + '0');
    // printf("%d", a.d[i]);
}

int main()
{
    char a[1000], b[1000];
    freopen("in.txt", "r", stdin);
    scanf("%s%s", a, b);
    print(add(change(a), change(b)));
    printf("\n");
    return 0;
}