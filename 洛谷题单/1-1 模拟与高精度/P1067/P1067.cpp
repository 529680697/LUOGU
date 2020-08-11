#include <iostream>

using namespace std;

int n, a;

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a;
        if (a != 0)
        {
            if (i == 0)
            {
                if (a == 1)
                    cout << "x^" << n - i;
                else if (a == -1)
                    cout << "-x^" << n - i;
                else
                    cout << a << "x^" << n - i;
            }
            else if (i != n)
            {
                if (a == -1)
                    cout << "-x";
                else if (a == 1)
                    cout << "+x";
                else if (a > 0)
                    cout << "+" << a << "x";
                else
                    cout << a << "x";
                if (i != n - 1)
                    cout << "^" << n - i;
            }
            else
            {
                if (a < 0)
                    cout << a;
                else
                    cout << "+" << a;
            }
        }
    }
    cout << endl;
    return 0;
}