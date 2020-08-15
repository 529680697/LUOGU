#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

ll n, slen;
char s[40];
ll len[100];

char f(ll i)
{
    while (i >= slen)
        i = (i - 1) % len[(int)log2(i / slen)];
    return s[i];
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> s >> n;
    slen = strlen(s);
    if (slen == 1)
    {
        cout << s << endl;
        return 0;
    }
    len[0] = slen;
    for (int i = 1; i < 65; i++)
        len[i] = len[i - 1] << 1;
    cout << f(n - 1) << endl;
    return 0;
}