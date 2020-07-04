#include <iostream>
#include <math.h>

using namespace std;

int s[1001];

bool sgn(int num) {
    return num < 0 ? 1:0;
}

int find_s(int *s, int n, int num) {
    for (int i = 1; i <= n; i++) {
        if (s[i] == num) {
            return i;
        }
    }
    return 0;
}

void judge(int *s, int n, int location, int p, int q, bool l) {
    if (l) {  //向左移动
        int i;
        for (i = 0; i < q; i++)
        {
            s[location-i] = s[location-i-1];
        }
        s[location-i] = p;
    } else {  //向后移动
        int i;
        for (i = 0; i < q; i++)
        {
            s[location+i] = s[location+i+1];
        }
        s[location+i] = p;
    }
}

int main () {
    int n, m;
    int p, q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        s[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        judge(s, n, find_s(s, n, p), p, abs(q), sgn(q));
    }
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << ' ';
    }
    system("pause");
    return 0;
}
