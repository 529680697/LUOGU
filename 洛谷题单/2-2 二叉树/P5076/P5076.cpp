#include <iostream>
#include <set>

using namespace std;
typedef multiset<int>::iterator iter;

int n;
multiset<int> s;

int main()
{
    int op, x, ans;
    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    cin >> n;
    s.insert(-2147483647), s.insert(2147483647);
    for (int i = 0; i < n; i++)
    {
        cin >> op >> x;
        switch (op)
        {
        case 1:
        {
            iter it = s.lower_bound(x);
            ans = 0;
            for (iter it1 = s.begin(); it1 != it; it1++, ans++)
                ;
            cout << ans << endl;
        }
        break;
        case 2:
        {
            int i = 0;
            iter it;
            for (it = s.begin(); i != x; it++, i++)
                ;
            cout << *it << endl;
        }
        break;
        case 3:
        {
            iter it = s.lower_bound(x);
            cout << *(--it) << endl;
        }
        break;
        case 4:
        {
            iter it = s.upper_bound(x);
            cout << *it << endl;
        }
        break;
        case 5:
            s.insert(x);
            break;
        }
    }
    return 0;
}