#include <iostream>

using namespace std;

bool f[101][101];

void draw(bool f[101][101], int x1, int y1, int x2, int y2) {
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            f[i][j] = 1;
        }
    }
    
}

int main() {
    int n, area = 0;
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        draw(f, x1, y1, x2, y2);
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (f[i][j]) {
                area++;
            }
        }
    }
    cout << area;
    system("pause");
    return 0;
}