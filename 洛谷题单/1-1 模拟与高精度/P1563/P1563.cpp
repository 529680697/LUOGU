#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node
{
    bool forward;
    string name;
    node(bool _f, string _s) : forward(_f), name(_s) {}
};

int n, m, cur = 0, num;
vector<node> v;
bool lr;

int main()
{
    bool a;
    string s;
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> s;
        v.push_back(node(a, s));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> lr >> num;
        if (lr == 0 && v[cur].forward == 0)
        {
            cur = (cur + n - num) % n;
        }
        else if (lr == 1 && v[cur].forward == 0)
        {
            cur = (cur + num) % n;
        }
        else if (lr == 0 && v[cur].forward == 1)
        {
            cur = (cur + num) % n;
        }
        else
        {
            cur = (cur + n - num) % n;
        }
    }
    cout << v[cur].name << endl;
    return 0;
}