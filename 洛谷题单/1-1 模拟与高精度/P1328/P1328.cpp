#include <iostream>

using namespace std;
const int maxn = 205;

int n, n1, n2, a1[maxn], a2[maxn];
int f[5][5] = {{0, -1, 1, 1, -1}, {1, 0, -1, 1, -1}, {-1, 1, 0, -1, 1}, {-1, -1, 1, 0, 1}, {1, 1, -1, -1, 0}};

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> n1 >> n2;
    for (int i = 0; i < n1; i++)
        cin >> a1[i];
    for (int i = 0; i < n2; i++)
        cin >> a2[i];
    int ans, num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        ans = f[a1[i % n1]][a2[i % n2]];
        if (ans == 1)
            num1++;
        else if (ans == -1)
            num2++;
    }
    cout << num1 << " " << num2 << endl;
    return 0;
}