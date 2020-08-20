#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 100005;

int n, p, a[maxn], b[maxn];

bool check(double x)
{
    double sum = x * (double)p;
    for (int i = 0; i < n; i++)
    {
        double tmp = (double)b[i] - (double)a[i] * x;
        if (tmp >= 0)
            continue;
        if (sum < -tmp)
            return false;
        sum += tmp;
    }
    return true;
}

int main()
{
    freopen("in", "r", stdin);
    double sum = 0;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p)
        cout << -1 << endl;
    else
    {
        double l = 0, r = 1e10, mid;
        while (r - l >= 1e-6)
        {
            mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.10lf\n", l);
    }
    return 0;
}