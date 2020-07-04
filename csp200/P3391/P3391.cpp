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

inline bool l_or_r(int x) //�ж�xΪ���ӻ����Һ���
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
    int now = ++node_num;                        //���ڽڵ�����
    s[now].f = fa;                               //ָ�����ڵ�
    s[now].son[0] = s[now].son[1] = 0;           //���ӽڵ�Ϊ��
    s[now].cnt++;                                //�ǵڼ��������ýڵ��
    s[now].value = seq[mid];                     //�����Ľڵ�ı��/Ȩֵ
    s[now].size++;                               //�ڵ���Ŀ��ʼ��Ϊ����ڵ���Ŀ
    s[now].son[0] = build_tree(l, mid - 1, now); //�ݹ鴴��������
    s[now].son[1] = build_tree(mid + 1, r, now); //�ݹ鴴��������
    update(now);                                 //�������ڵ�����
    return now;
}

inline void pushdown(int x) //��x�����������з�ת��������
{
    if (x && s[x].tag)
    {
        s[s[x].son[0]].tag ^= 1; //��ʾx�ڵ�����ӱ���ת��
        s[s[x].son[1]].tag ^= 1; //��ʾx�ڵ���Һ��ӱ���ת��
        swap(s[x].son[1], s[x].son[0]);
        s[x].tag = 0;
    }
}

inline int find(int x) //Ѱ�ҵ���x�Žڵ����ڵ�λ��
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
    int f_now = s[x].f;                //��ǰ�ڵ㸸�ڵ�
    int ff_now = s[f_now].f;           //��ǰ�ڵ�үү�ڵ�
    bool w = l_or_r(x);                //�ж�xΪ���ӻ����Һ���
    s[f_now].son[w] = s[x].son[w ^ 1]; //��x�ĺ��Ӵ���x�ڵ��λ��
    s[s[f_now].son[w]].f = f_now;      //x�ĺ�����x�ĸ���������
    s[f_now].f = x;                    //x���׵ĸ��ױ�Ϊx
    s[x].f = ff_now;                   //x�ĸ��ױ�Ϊԭ��x��үү
    s[x].son[w ^ 1] = f_now;           //x�Ķ��ӱ�Ϊԭ��x�ĸ���
    if (ff_now)                        //��xүү�ǿգ���������ӽڵ�
    {
        s[ff_now].son[s[ff_now].son[1] == f_now] = x;
    }
    update(f_now);
}

inline void splay(int x, int g) //��x�ڵ�����Ŀ��ڵ�g
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