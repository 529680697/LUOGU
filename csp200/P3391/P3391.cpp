#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;

int node_num, seq[100005], root;
struct splay_tree
{
    int f, size, cnt, value, tag;
    int son[2];
} s[100005];

inline bool l_or_r(int x) //判断x为左孩子还是右孩子
{
    return x == s[s[x].f].son[1];
}

inline void update(int x)
{
    if (x)
    {
        s[x].size = s[x].cnt;
        if (s[x].son[0])
        {
            s[x].size += s[s[x].son[0]].size;
        }
        if (s[x].son[1])
        {
            s[x].size += s[s[x].son[1]].size;
        }
    }
}

int build_tree(int l, int r, int fa)
{
    if (l > r)
        return 0;
    int mid = (l + r) >> 1;
    int now = ++node_num;                        //现在节点的序号
    s[now].f = fa;                               //指定父节点
    s[now].son[0] = s[now].son[1] = 0;           //儿子节点为空
    s[now].cnt++;                                //是第几个创建该节点的
    s[now].value = seq[mid];                     //创建的节点的编号/权值
    s[now].size++;                               //节点数目初始化为自身节点数目
    s[now].son[0] = build_tree(l, mid - 1, now); //递归创建左子树
    s[now].son[1] = build_tree(mid + 1, r, now); //递归创建右子树
    update(now);                                 //更新树节点数量
    return now;
}

inline void pushdown(int x) //对x左右子树进行翻转，即交换
{
    if (x && s[x].tag)
    {
        s[s[x].son[0]].tag ^= 1; //表示x节点的左孩子被翻转过
        s[s[x].son[1]].tag ^= 1; //表示x节点的右孩子被翻转过
        swap(s[x].son[1], s[x].son[0]);
        s[x].tag = 0;
    }
}

inline int find(int x) //寻找到第x号节点所在的位置
{
    int now = root;
    while (true)
    {
        pushdown(now);
        if (x <= s[s[now].son[0]].size)
        {
            now = s[now].son[0];
        }
        else
        {
            x -= s[s[now].son[0]].size + 1;
            if (!x)
                return now;
            now = s[now].son[1];
        }
    }
}

inline void rotate(int x)
{
    int f_now = s[x].f;                //当前节点父节点
    int ff_now = s[f_now].f;           //当前节点爷爷节点
    bool w = l_or_r(x);                //判断x为左孩子还是右孩子
    s[f_now].son[w] = s[x].son[w ^ 1]; //用x的孩子代替x节点的位置
    s[s[f_now].son[w]].f = f_now;      //x的孩子认x的父亲做父亲
    s[f_now].f = x;                    //x父亲的父亲变为x
    s[x].f = ff_now;                   //x的父亲变为原来x的爷爷
    s[x].son[w ^ 1] = f_now;           //x的儿子变为原来x的父亲
    if (ff_now)                        //若x爷爷非空，更新其儿子节点
    {
        s[ff_now].son[s[ff_now].son[1] == f_now] = x;
    }
    update(f_now);
}

inline void splay(int x, int g) //将x节点旋到目标节点g
{
    for (int i; (i = s[x].f) != g; rotate(x))
    {
        if (s[i].f != g)
        {
            rotate(l_or_r(x) == l_or_r(i) ? i : x);
        }
    }
    if (g == 0)
    {
        root = x;
    }
}

inline void reverse(int x, int y)
{
    int l = x - 1, r = y + 1;
    l = find(l);
    r = find(r);
    splay(l, 0);
    splay(r, l);
    int pos = s[root].son[1];
    pos = s[pos].son[0];
    s[pos].tag ^= 1;
}

inline void dfs(int now)
{
    pushdown(now);
    if (s[now].son[0])
        dfs(s[now].son[0]);
    if (s[now].value != -INF && s[now].value != INF)
    {
        cout << s[now].value << " ";
    }
    if (s[now].son[1])
        dfs(s[now].son[1]);
}

int main()
{
    int n, m, l, r;
    cin >> n >> m;
    seq[1] = -INF, seq[n + 2] = INF;
    for (int i = 1; i <= n; i++)
    {
        seq[i + 1] = i;
    }
    root = build_tree(1, n + 2, 0);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &l, &r);
        reverse(l + 1, r + 1);
    }
    dfs(root);
}