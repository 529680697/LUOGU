#include <iostream>

using namespace std;

int s[40][40];
int f[40][40];

void row(int s[40][40], int f[40][40], int num, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == num) {
                int count = 1;
                while (num == s[i][j+count]) {
                    count ++;
                }
                if (count > 2) {
                    for (int k = 0; k < count; k++) {
                        f[i][j+k] = 1;
                    }
                }
                j += count;
            }
        }
    }
}

void column(int s[40][40], int f[40][40], int num, int n, int m){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j][i] == num) {
                int count = 1;
                while (num == s[j+count][i]) {
                    count ++;
                }
                if (count > 2) {
                    for (int k = 0; k < count; k++) {
                        f[j+k][i] = 1;
                    }
                }
                j += count;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            f[i][j] = 0;
        }
    }
    for (int i = 1; i < 10; i++) {
        row(s, f, i, n, m);
        column(s, f, i, n, m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if (f[i][j]) {
               s[i][j] = 0;
           } 
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           cout << s[i][j] << ' '; 
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}