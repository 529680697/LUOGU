#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> ans;
struct Rule
{
    string r, v;
} rule[1000];

inline void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> rule[i].r >> rule[i].v;
        //cout << rule[i].r << " " << rule[i].v << endl;
    }
}

inline bool is_num(string s) //�ж�s�Ƿ�Ϊ����
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

inline bool match(string s1, string s2)
{
    ans.clear();
    //bool flag = false; //��ʾ�ù����Ƿ�Ϊpath��
    string t_s1, t_s2;
    int l_pos1 = 0, l_pos2 = 0;
    int pos1 = s1.find("/", 1);
    int pos2 = s2.find("/", 1);
    if (pos1 != string::npos && pos2 != string::npos)
    {
        t_s1 = s1.substr(1, pos1 - 1);
        t_s2 = s2.substr(1, pos2 - 1);
    }
    else if (pos1 == string::npos && pos2 != string::npos)
    {
        t_s1 = s1.substr(1);
        t_s2 = s2.substr(1, pos2 - 1);
    }
    else if (pos1 != string::npos && pos2 == string::npos)
    {
        t_s1 = s1.substr(1, pos1 - 1);
        t_s2 = s2.substr(1);
    }
    else
    {
        t_s1 = s1.substr(1);
        t_s2 = s2.substr(1);
    }
    //cout << t_s1 << " " << t_s2 << endl;
    while (!t_s1.empty() || !t_s2.empty())
    {
        if (t_s1 != t_s2)
        {
            if (t_s2 == "<path>") //����Ϊ<path>
            {
                if (t_s1.empty()) //��ƥ��Ϊ��
                    return false;
                else //��ƥ��b��Ϊ��
                {
                    // if (s1.back() == '/')
                    // {
                    //     ans.push_back(s1.substr(l_pos1 + 1, s1.size() - l_pos1 - 2)); //�������
                    // }
                    // else
                    ans.push_back(s1.substr(l_pos1 + 1)); //�������
                    return true;
                }
            }
            else if (t_s2 == "<str>") //����Ϊ<str>
            {
                if (t_s1.empty())
                    return false;
                ans.push_back(t_s1); //�������
            }
            else if (t_s2 == "<int>") //����Ϊ<int>
            {
                if (t_s1.empty() || !is_num(t_s1)) //��ƥ�䲻Ϊ����
                    return false;
                ans.push_back(to_string(atoi(t_s1.c_str()))); //�������
            }
            else
                return false;
        }
        //��ƥ�䲻Ϊ��
        l_pos1 = pos1;
        l_pos2 = pos2;
        pos1 = s1.find("/", l_pos1 + 1);
        pos2 = s2.find("/", l_pos2 + 1);
        if (pos1 != string::npos && pos2 != string::npos)
        {
            t_s1 = s1.substr(l_pos1 + 1, pos1 - l_pos1 - 1);
            t_s2 = s2.substr(l_pos2 + 1, pos2 - l_pos2 - 1);
        }
        else if (pos1 == string::npos && pos2 != string::npos)
        {
            t_s1 = s1.substr(l_pos1 + 1);
            t_s2 = s2.substr(l_pos2 + 1, pos2 - l_pos2 - 1);
        }
        else if (pos1 != string::npos && pos2 == string::npos)
        {
            t_s1 = s1.substr(l_pos1 + 1, pos1 - l_pos1 - 1);
            t_s2 = s2.substr(l_pos2 + 1);
        }
        else
        {
            t_s1 = s1.substr(l_pos1 + 1);
            t_s2 = s2.substr(l_pos2 + 1);
        }
        //cout << t_s1 << " " << t_s2 << endl;
    }
    if (t_s1.empty() && t_s2.empty() && ((s1.back() == '/' && s2.back() == '/') || (s1.back() != '/' && s2.back() != '/')))
        return true;
    else
        return false;
}

inline bool legal(string s)
{
    if (s[0] != '/')
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
            continue;
        if (s[i] <= 'z' && s[i] >= 'a')
            continue;
        if (s[i] <= '9' && s[i] >= '0')
            continue;
        if (s[i] == '/' || s[i] == '-' || s[i] == '_' || s[i] == '.')
            continue;
        return false;
    }
    return true;
}

int main()
{
    init(); //�������
    string s1;
    // match(s1, rule[3].r);
    for (int i = 0; i < m; i++)
    {
        cin >> s1;
        if (s1 == "/")
        {
            cout << rule[0].v << endl;
            continue;
        }
        if (!legal(s1))
        {
            cout << "404" << endl;
            continue;
        }
        int k;
        for (k = 0; k < n; k++)
        {
            if (match(s1, rule[k].r))
            {
                cout << rule[k].v;
                for (int j = 0; j < ans.size(); j++)
                {
                    cout << " " << ans[j];
                }
                cout << endl;
                break;
            }
        }
        if (k == n)
            cout << "404" << endl;
    }
    return 0;
}