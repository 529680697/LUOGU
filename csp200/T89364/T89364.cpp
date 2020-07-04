#include <iostream>

using namespace std;

int s[16][11];
int t[5][5];

bool can_fall(int s[16][11], int t[5][5], int n, int m) {
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            if (s[n+j][m+k]+t[j][k] == 2) {
                return false;
            }
        }
    }
    return true;
}

void fall(int s[16][11], int t[5][5], int n, int m) {
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            s[n+j][m+k] += t[j][k];
        }
    }
}

int main() {
    int n;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> t[i][j];
        }
    }
    cin >> n;
    for (int i = 1; i < 16; i++) {
        if (can_fall(s, t, i, n-1)) {
            ;
        } else {
            fall(s, t, i-1, n-1);
            break;
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}