#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;

inline void delete_zero()
{
    while (s.length() > 1 && s[0] == '0')
        s.erase(s.begin());
}

inline int get_hill()
{
    int now = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[now] > s[i])
            return now;
        else
            now = i;
    }
    return now;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> s >> k;
    while (k--)
    {
        s.erase(s.begin() + get_hill());
        // cout << s << endl;
        delete_zero();
    }
    cout << s << endl;
    return 0;
}