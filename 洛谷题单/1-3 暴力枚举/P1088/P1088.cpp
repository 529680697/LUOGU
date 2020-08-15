#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 10005;

int n, k, a[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (k--)
        next_permutation(a, a + n);
    cout << a[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << a[i];
    }
    return 0;
}