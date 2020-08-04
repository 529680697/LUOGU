#include <iostream>
#include <algorithm>
#define lowbit(i) ((i) & (-i))
using namespace std;
typedef long long ll;
const int maxn = 20005;

struct node
{
    int v, x;
} cows[maxn];

int n;
ll X[maxn], x_num[maxn];

bool cmp(node a, node b)
{
    return a.v < b.v;
}

void update(int x, ll v)
{
    for (int i = x; i < maxn; i += lowbit(i))
    {
        X[i] += v;
        x_num[i] += 1;
    }
}

ll get_sum(int x, ll &X_num)
{
    ll sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += X[i];
        X_num += x_num[i];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cows[i].v >> cows[i].x;
    sort(cows, cows + n, cmp);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        update(cows[i].x, cows[i].x);
        ll num_all = 0, num_left = 0, num_right = 0, sum_right, sum_left;
        sum_right = get_sum(maxn, num_all) - get_sum(cows[i].x, num_left);
        num_right = num_all - num_left;
        num_left = 0;
        sum_left = get_sum(cows[i].x - 1, num_left);
        ans += cows[i].v * (sum_right + cows[i].x * (num_left - num_right) - sum_left);
        // cout << sum_right << " " << sum_left << " " << num_all << " " << num_right << " " << num_left << endl;
    }
    cout << ans << endl;
    return 0;
}