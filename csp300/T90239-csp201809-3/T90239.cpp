#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int now_father = 1; //��ʾ�������ڴ����Ľڵ�ĸ���
int now_depth = 0;  //��ʾ���ڵĸ��׽ڵ����ڵ����
string t_s;         //������ʱ�����һ���ַ���

struct Node
{
    string id, tag;
    int depth;
    bool flag; //���ʱ��
    vector<int> child;
    int fa;
} node[1000];

int dfs(string s, int nod, set<int> &ans)
{
    string temp_s;
    int pos = s.find(" ");
    if (pos == string::npos)
    {
        if (s[0] == '#') //�����ҵ�Ϊid
        {
            for (int i = 0; i < node[nod].child.size(); i++)
            {
                if (s == node[node[nod].child[i]].id) //�ҵ�һ���𰸽ڵ�
                {
                    ans.insert(node[nod].child[i]);
                }
                dfs(s, node[nod].child[i], ans);
            }
        }
        else //�����ҵ�Ϊtag
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower); //tagתСд
            for (int i = 0; i < node[nod].child.size(); i++)
            {
                if (s == node[node[nod].child[i]].tag) //�ҵ�һ���𰸽ڵ�
                {
                    ans.insert(node[nod].child[i]);
                }
                dfs(s, node[nod].child[i], ans);
            }
        }
    }
    else
    {
        temp_s = s.substr(0, pos); //��ȡ
        if (temp_s[0] == '#')      //�����ҵ�Ϊid
        {
            for (int i = 0; i < node[nod].child.size(); i++)
            {
                if (temp_s == node[node[nod].child[i]].id) //�ü�Ԫ��ƥ�䣬������һ����ƥ��
                {
                    dfs(s.substr(pos + 1), node[nod].child[i], ans);
                }
                dfs(s, node[nod].child[i], ans); //�����ü�������һ����ʼƥ��
            }
        }
        else //�����ҵ�Ϊtag
        {
            transform(temp_s.begin(), temp_s.end(), temp_s.begin(), ::tolower); //tagתСд
            for (int i = 0; i < node[nod].child.size(); i++)
            {
                if (temp_s == node[node[nod].child[i]].tag) //�ü�Ԫ��ƥ�䣬������һ����ƥ��
                {
                    dfs(s.substr(pos + 1), node[nod].child[i], ans);
                }
                dfs(s, node[nod].child[i], ans); //�����ü�������һ����ʼƥ��
            }
        }
    }
    return 0;
}

inline int get_depth(string ts)
{
    int count = 0;
    for (int i = 0; (i = ts.find(".", i)) < ts.length(); i++)
    {
        count++;
    }
    return count >> 1;
}

int main()
{
    cin >> n >> m >> t_s;
    getchar();
    node[0].child.push_back(1);
    node[0].depth = -1;
    node[1].tag = t_s;
    node[1].depth = 0;
    node[1].id.clear();
    node[1].child.clear();
    node[1].fa = 0;
    node[1].flag = false;
    for (int i = 2; i <= n; i++) //����
    {
        getline(cin, t_s);
        node[i].depth = get_depth(t_s);
        node[i].child.clear();
        node[i].flag = false;
        int pos = 0; //����#��λ��
        if ((pos = t_s.find("#")) == string::npos)
        {
            node[i].tag = t_s.substr(node[i].depth << 1);
            transform(node[i].tag.begin(), node[i].tag.end(), node[i].tag.begin(), ::tolower); //tagתСд
            //cout << node[i].tag << endl;
            node[i].id.clear();
        }
        else
        {
            node[i].tag = t_s.substr(node[i].depth << 1, pos - 1 - (node[i].depth << 1));
            transform(node[i].tag.begin(), node[i].tag.end(), node[i].tag.begin(), ::tolower); //tagתСд
            //cout << node[i].tag << endl;
            node[i].id = t_s.substr(pos);
            //cout << node[i].id << endl;
        }
        if (node[i].depth - now_depth == 1) //�����Ľڵ�Ϊ�ָ��׽ڵ�Ķ���
        {
            node[i].fa = now_father;
            node[now_father].child.push_back(i);
        }
        else if (node[i].depth - now_depth == 2) //�����Ľڵ�Ϊ�ָ��׽ڵ������
        {
            now_father = node[now_father].child.back();
            now_depth = node[now_father].depth;
            node[i].fa = now_father;
            node[now_father].child.push_back(i);
        }
        else
        {
            for (int j = 0; j < now_depth - node[i].depth + 1; j++)
            {
                now_father = node[now_father].fa;
            }
            now_depth = node[now_father].depth;
            node[i].fa = now_father;
            node[now_father].child.push_back(i);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << node[i].depth << " " << node[i].tag << " " << node[i].id << "  " << node[i].child.size() << endl;
    // }

    vector<set<int>> ans;
    set<int> a;
    for (int i = 0; i < m; i++)
    {
        ans.push_back(a);
        ans[i].clear();
        getline(cin, t_s);
        // cout << t_s << endl;
        dfs(t_s, 0, ans[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i].size();
        for (set<int>::iterator it = ans[i].begin(); it != ans[i].end(); it++)
        {
            cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}