#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n;
string s[2000];

void add(int end)
{
    for (int i = end; i < (end << 1); i++)
    {
        s[i] = s[i - end] + s[i - end];
    }
    for (int i = 0; i < end; i++)
    {
        s[i].insert(0, end, ' ');
        s[i].insert(s[i].length(), end, ' ');
    }
}

int main()
{
    cin >> n;
    s[0] = " /\\ ";
    s[1] = "/__\\";
    for (int i = 1; i < n; i++)
    {
        add(1 << i);
    }
    for (int i = 0; i < (1 << n); i++)
    {
        cout << s[i] << endl;
    }

    return 0;
}