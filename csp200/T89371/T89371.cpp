#include <iostream>

using namespace std;

struct window {
    int x1, y1, x2, y2;
    int num;
}win[11];

int click[11][2];

bool in_the_window(struct window win, int x, int y) {
    if (win.x1 <= x && x <= win.x2 && win.y1 <= y && y <= win.y2) {
        return true;
    } else {
        return false;
    }
}

int find_window(struct window win[11], int n, int k) {
    for (int i = 1; i <= n; i++) {
        if (win[i].num == k) {
            return i;
        }
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> win[i].x1 >> win[i].y1 >> win[i].x2 >> win[i].y2;
        win[i].num = n-i+1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> click[i][0] >> click[i][1];
    }
    for (int i = 1; i <= m; i++) {
        bool flag = 0;
        int number;
        for (int j = 1; j <=n; j++) {
            number = find_window(win, n, j);
            if (in_the_window(win[number], click[i][0], click[i][1])) {
                cout << number << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "IGNORED" << endl;
        } else {
            int temp_num = win[number].num;
            for (int k = 1; k <= n; k++) {
                if (win[k].num < temp_num) {
                    win[k].num++;
                }
            }
            win[number].num = 1;
        }
    }
    system("pause");
    return 0;
}