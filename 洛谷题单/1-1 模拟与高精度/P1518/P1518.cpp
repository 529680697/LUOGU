#include <iostream>
#include <set>

using namespace std;

struct node_to //牛和John的朝向
{
    int x, y;
} to[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //上、右、下、左

struct node
{
    node_to c, f;
    int c_to, f_to;
    node() {}
    node(node_to _c, node_to _f, int _cto, int _fto) : c(_c), f(_f), c_to(_cto), f_to(_fto) {}
};

class node_sort
{
public:
    bool operator()(const node &a, const node &b) const
    {
        if (a.c_to < b.c_to)
            return true;
        else if (a.c_to == b.c_to)
        {
            if (a.f_to < b.f_to)
                return true;
            else if (a.f_to == b.f_to)
            {
                if (a.c.x < b.c.x)
                    return true;
                else if (a.c.x == b.c.x)
                {
                    if (a.c.y < b.c.y)
                        return true;
                    else if (a.c.y == b.c.y)
                    {
                        if (a.f.x < b.f.x)
                            return true;
                        else if (a.f.x == b.f.x)
                        {
                            if (a.f.y < b.f.y)
                                return true;
                            else
                                return false;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
};

char f[12][12];
int f_to, c_to;
set<node, node_sort> s;
node_to F, C;

inline void find_f(int &x, int &y)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (f[i][j] == 'F')
                x = i, y = j;
}

inline void find_c(int &x, int &y)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (f[i][j] == 'C')
                x = i, y = j;
}

inline bool vaild(int x, int y, int i) //判断按当前方向是否可以前进
{
    x += to[i].x, y += to[i].y;
    return 0 <= x && x < 10 && 0 <= y && y < 10 && f[x][y] != '*';
}

bool deal()
{
    if (vaild(F.x, F.y, f_to))
    {
        F.x += to[f_to].x, F.y += to[f_to].y;
    }
    else
    {
        f_to = (f_to + 1) % 4;
    }

    if (vaild(C.x, C.y, c_to))
    {
        C.x += to[c_to].x, C.y += to[c_to].y;
    }
    else
    {
        c_to = (c_to + 1) % 4;
    }
    node tmp = node(C, F, c_to, f_to);
    if (s.find(tmp) == s.end())
    {
        s.insert(tmp);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    for (int i = 0; i < 10; i++)
        cin >> f[i];
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << f[i] << endl;
    // }
    find_f(F.x, F.y), find_c(C.x, C.y);
    int ans = 0;
    while (F.x != C.x || C.y != F.y)
    {
        if (!deal())
        {
            cout << 0 << endl;
            return 0;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}