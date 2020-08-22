#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef set<int>::iterator iter;
const int inf = 0x3f3f3f3f;

int n;
set<int> s;

int main()
{
    int op, l;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    s.insert(-inf), s.insert(inf);
    for (int i = 0; i < n; i++)
    {
        cin >> op >> l;
        if (op == 1)
        {
            iter it = s.lower_bound(l);
            if (*it == l)
                cout << "Already Exist" << endl;
            else
                s.insert(l);
        }
        else
        {
            if (s.size() == 2)
                cout << "Empty" << endl;
            else
            {
                iter it = s.lower_bound(l);
                if (*it != l)
                {
                    if (*it == inf)
                        it--;
                    else
                    {
                        iter i1 = --it;
                        it++;
                        if (*i1 != -inf && *it - l >= l - *i1)
                            it--;
                    }
                }
                cout << *it << endl;
                s.erase(it);
            }
        }
    }
    return 0;
}