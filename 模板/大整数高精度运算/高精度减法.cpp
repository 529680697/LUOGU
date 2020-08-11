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

//两个bign进行相减，高精度，需确保 a > b
bign sub(bign a, bign b)
{
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        if (a.d[i] < b.d[i]) //不够减，借位
        {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) //去除高位的0，同时至少保留一位最低位
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
    char a[1000], b[1000];
    // freopen("in.txt", "r", stdin);
    scanf("%s%s", a, b);
    print(sub(change(a), change(b)));
    printf("\n");
    return 0;
}