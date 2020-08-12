#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int p1, p2, p3;
string s, d;

string deal(char a, char b)
{
    string tmp;
    char ttmp[1024];
    tmp.append(&a);
    if (isdigit(a) && isdigit(b))
    {
        if (a < b)
        {
            if (p1 == 3)
            {
                for (int i = 0; i < p2 * (b - a - 1); i++)
                    ttmp[i] = '*';
                ttmp[p2 * (b - a - 1)] = '\0';
                tmp.append(ttmp);
            }
            else
            {
                int j = 0;
                for (char c = a + 1; c < b; c++)
                    for (int i = 0; i < p2; i++)
                        ttmp[j++] = c;
                ttmp[j] = '\0';
                tmp.append(ttmp);
                if (p3 == 2)
                    reverse(tmp.begin() + 1, tmp.end());
            }
        }
        else if (a != b - 1)
            tmp.append("-");
    }
    else if (isalpha(a) && isalpha(b))
    {
        if (a < b)
        {
            if (p1 == 3)
            {
                for (int i = 0; i < p2 * (b - a - 1); i++)
                    ttmp[i] = '*';
                ttmp[p2 * (b - a - 1)] = '\0';
                tmp.append(ttmp);
            }
            else
            {
                char ta = a, tb = b;
                if (p1 == 2)
                    ta += 'A' - 'a', tb += 'A' - 'a';
                int j = 0;
                for (char c = ta + 1; c < tb; c++)
                    for (int i = 0; i < p2; i++)
                        ttmp[j++] = c;
                ttmp[j] = '\0';
                tmp.append(ttmp);
                if (p3 == 2)
                    reverse(tmp.begin() + 1, tmp.end());
            }
        }
        else if (a != b - 1)
            tmp.append("-");
    }
    else
        tmp.append("-");
    // tmp.append(&b);
    return tmp;
}

int main()
{
    char tmp_s[1024];
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> p1 >> p2 >> p3;
    scanf("%s", tmp_s);
    s = tmp_s;
    int pos = 0, last = 0;
    while (pos < s.length() - 1 && (pos = s.find("-", pos)) != string::npos)
    {
        if (pos == 0) // - 出现在第一位
        {
            // d.append("-");
            pos++;
            continue;
        }
        else if (pos != s.length() - 1) // - 不出现在字符串末尾
        {
            if (s[pos - 1] != '-' && s[pos + 1] != '-')
            {
                d.append(s.substr(last, pos - last - 1));
                d.append(deal(s[pos - 1], s[pos + 1]));
                last = ++pos;
            }
            else
                pos++;
        }
    }
    d.append(s.substr(last));
    printf("%s\n", d.c_str());

    return 0;
}