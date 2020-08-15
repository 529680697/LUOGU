#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

char tmp_s[20005];

int rfind(int begin, string s)
{
    int lnum = 0, rnum = 0;
    for (int i = begin; i < s.size(); i++)
    {
        if (s[i] == '[')
            lnum++;
        else if (s[i] == ']')
        {
            if (lnum == 1)
                return i;
            else
                lnum--;
        }
    }
    return -1;
}

string deal(string s)
{
    // cout << s << endl;
    string ts;
    int l = 0, r = 0, len = 0, num;
    while (isdigit(s[l++]))
    {
        len++;
    }
    num = atoi(s.substr(0, len).c_str());
    ts = s.substr(len);
    // cout << ts << endl;
    s = "";
    for (int i = 0; i < num; i++)
    {
        s.append(ts);
    }
    // cout << s << endl;
    l = 0;
    ts = "";
    while ((l = s.find("[", l)) != string::npos)
    {
        ts.append(s.substr(r, l - r));
        r = rfind(r, s);
        // cout << l << " " << r << endl;
        ts.append(deal(s.substr(l + 1, r - l - 1)));
        l = ++r;
    }
    // cout << s << endl;
    if (r != s.size())
        ts.append(s.substr(r));
    return ts;
}

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%s", tmp_s);
    string s = tmp_s;
    int l = 0, r = 0;
    string ts;
    while ((l = s.find("[", l)) != string::npos)
    {
        ts.append(s.substr(r, l - r));
        r = rfind(r, s);
        // cout << l << " " << r << endl;
        ts.append(deal(s.substr(l + 1, r - l - 1)));
        l = ++r;
    }
    if (r != s.size())
        ts.append(s.substr(r));
    cout << ts << endl;
    return 0;
}