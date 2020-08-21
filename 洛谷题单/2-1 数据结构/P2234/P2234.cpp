#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;

int n, a;
long long ans;
multiset<int> s;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> a;
    s.insert(inf), s.insert(-inf), s.insert(a);
    ans = a;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        multiset<int>::iterator it = s.insert(a);
        multiset<int>::iterator l = --it;
        it++, it++;
        multiset<int>::iterator r = it;
        if (*l == -inf)
            ans += *r - a;
        else if (*r == inf)
            ans += a - *l;
        else
            ans += min(*r - a, a - *l);
    }
    cout << ans << endl;
    return 0;
}