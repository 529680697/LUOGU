#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
    string a, b;
} no[200005];

int n, num[1000][1000];
bool vis[1000][1000];

inline int hash_func(string a)
{
    return (a[0] - 'A') * 26 + a[1] - 'A';
}

int main()
{
    string a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> no[i].a >> no[i].b;
        num[hash_func(no[i].a)][hash_func(no[i].b)]++;
    }
    int i1, i2;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        i1 = hash_func(no[i].a);
        i2 = hash_func(no[i].b);
        if (!vis[i1][i2] && i1 != i2 && num[i2][i1])
        {
            vis[i1][i2] = true;
            ans += num[i1][i2] * num[i2][i1];
        }
    }
    cout << (ans >> 1) << endl;
    return 0;
}