#include <iostream>
#include <cstdio>

#define MAXN 100005

using namespace std;

int n, m, q;

class treeArray
{
private:
    int c[MAXN];
    int a[MAXN];

public:
    treeArray()
    {
        for (int i = 0; i < MAXN; i++)
        {
            a[i] = -1;
            c[i] = 0;
        }
    }
    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int i, int l)
    {
        a[i] = -a[i];
        int k = i;
        while (i <= l)
        {
            c[i] += a[k];
            i += lowbit(i);
        }
    }

    int sum(int i)
    {
        int r = 0;
        while (i > 0)
        {
            r += c[i];
            i -= lowbit(i);
        }
        return r;
    }
} dx, dy;

long long calaculate(int x1, int y1, int x2, int y2)
{
    int s1 = dx.sum(x2) - dx.sum(x1 - 1);
    int s2 = dy.sum(y2) - dy.sum(y1 - 1);
    long long ans = (long long)s1 * (y2 - y1 + 1) + (long long)s2 * (x2 - x1 + 1) - 2 * s1 * s2;
    return ans;
}

int main()
{
    cin >> n >> m >> q;
    int op, x1, y1, x2, y2;
    for (int i = 0; i < q; i++)
    {
        cin >> op >> x1 >> y1;
        if (op == 2)
        {
            cin >> x2 >> y2;
            cout << calaculate(x1, y1, x2, y2) << endl;
        }
        else
        {
            dx.add(x1, n);
            dy.add(y1, m);
        }
    }
    return 0;
}