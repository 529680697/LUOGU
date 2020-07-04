#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
map<string, string> ans;

inline void format(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '\\')
            s.erase(s.begin() + i);
}

void deal(string s, string head)
{
    string key, value;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '"')
        {
            int j = s.find(":", i + 1);
            key = s.substr(i + 1, j - i - 2);
            if (head != "")
                key = head + "." + key;
            if (s[j + 1] == '"') //键值为字符串
            {
                if (s.find(',', j + 1) != string::npos)
                    i = s.find(',', j + 1);
                else
                    i = s.size() - 1;
                value = s.substr(j + 2, i - j - 3);
            }
            else //键值为对象
            {
                int count = 1;
                i = j + 2;
                while (count != 0)
                {
                    if (s[i] == '{')
                        ++count;
                    else if (s[i] == '}')
                        --count;
                    ++i;
                }
                value = "{}";
                deal(s.substr(j + 1, i - j - 1), key);
            }
            ans[key] = value;
        }
    }
}

int main()
{
    cin >> n >> m;
    string t_s, s;
    getline(cin, t_s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, t_s);
        for (string::iterator it = t_s.begin(); it != t_s.end();) //去除所有多余空格
            if (isspace(*it))
                it = t_s.erase(it);
            else
                ++it;
        s += t_s;
    }
    string h;
    format(s);
    deal(s, h);
    for (int i = 0; i < m; i++)
    {
        cin >> t_s;
        if (ans.find(t_s) != ans.end())
            if (ans[t_s] == "{}")
                cout << "OBJECT" << endl;
            else
                cout << "STRING " << ans[t_s] << endl;
        else
            cout << "NOTEXIST" << endl;
    }
    return 0;
}