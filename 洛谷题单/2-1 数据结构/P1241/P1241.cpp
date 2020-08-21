#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int vis[1024];

int main()
{
    freopen("in", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == '(' && vis[j] == 0)
                {
                    vis[j] = vis[i] = 2;
                    break;
                }
                else if (s[j] == '[' && vis[j] == 0)
                {
                    vis[i] = 1;
                    break;
                }
            }
        }
        else if (s[i] == ']')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == '[' && vis[j] == 0)
                {
                    vis[j] = vis[i] = 2;
                    break;
                }
                else if (s[j] == '(' && vis[j] == 0)
                {
                    vis[i] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (vis[i] == 2)
            putchar(s[i]);
        else
        {
            if (s[i] == '[' || s[i] == ']')
                putchar('['), putchar(']');
            else if (s[i] == '(' || s[i] == ')')
                putchar('('), putchar(')');
        }
    }
    cout << endl;
    return 0;
}
