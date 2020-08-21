#include <iostream>

using namespace std;
const int maxn = 100005;

struct node
{
    int no, pre, next;
} a[maxn];

int n, m, b[maxn], cur = 1;
bool inq[maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    int k, p;
    cin >> n;
    a[cur].no = 1, a[cur].pre = a[cur].next = 0;
    a[0].next = a[0].pre = 1;
    b[1] = cur;
    cur++;
    for (int i = 2; i <= n; i++, cur++)
    {
        cin >> k >> p;
        a[cur].no = i, b[i] = cur;
        if (p)
        {
            a[cur].pre = b[k], a[cur].next = a[b[k]].next;
            a[b[k]].next = cur, a[a[cur].next].pre = cur;
        }
        else
        {
            a[cur].pre = a[b[k]].pre, a[cur].next = b[k];
            a[a[cur].pre].next = cur, a[a[cur].next].pre = cur;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        if (!inq[k])
        {
            inq[k] = true;
            a[a[b[k]].pre].next = a[b[k]].next;
            a[a[b[k]].next].pre = a[b[k]].pre;
        }
    }
    for (int i = a[0].next; a[i].no != 0; i = a[i].next)
    {
        cout << a[i].no << " ";
    }
    cout << endl;
    return 0;
}