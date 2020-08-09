#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct node
{
    int d[1000];
    int len;
    node()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

node add(node a, node b)
{
    node c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0)
        c.d[c.len++] = carry;
    return c;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int k;
    string x;
    cin >> k >> x;
    node a = node(), b = node();
    a.len = x.size();
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = x[a.len - i - 1] - '0';
    }
    b.len = k + 1;
    b.d[k] = 1;
    node c = add(a, b);
    for (int i = c.len - 1; i >= 0; i--)
    {
        printf("%d", c.d[i]);
    }
    printf("\n");
    return 0;
}