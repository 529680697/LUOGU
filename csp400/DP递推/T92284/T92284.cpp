#include <iostream>

using namespace std;

struct node
{
    int l1, l2, l3, d;
    int get_sum()
    {
        return l1 + l2 + l3 + d;
    }
} cow[60];

int n;

int main()
{
    cow[1].l1 = cow[1].l2 = cow[1].l3 = 0, cow[1].d = 1;
    cow[2].l1 = 1, cow[2].l2 = cow[2].l3 = 0, cow[2].d = 1;
    cow[3].l1 = cow[3].l2 = 1, cow[3].l3 = 0, cow[3].d = 1;
    cow[4].l1 = cow[4].l2 = cow[4].l3 = 1, cow[4].d = 1;
    for (int i = 5; i < 56; i++)
    {
        cow[i].d = cow[i - 1].l3 + cow[i - 1].d;
        cow[i].l3 = cow[i - 1].l2;
        cow[i].l2 = cow[i - 1].l1;
        cow[i].l1 = cow[i].d;
    }
    cin >> n;
    while (n)
    {
        cout << cow[n].get_sum() << endl;
        cin >> n;
    }
    return 0;
}