#include <iostream>

using namespace std;

int h[1001];

int find_highest(int *h, int n) {
    int highest = 0;
    for (int i = 0; i < n; i++) {
        if (highest < h[i]) {
            highest = h[i];
        }
    }
    return highest;
}

int find_widest(int *h, int n, int height) {
    int widest = 1;
    for (int i = 0; i < n; i++) {
        if (h[i] >= height) {
            int temp = 1;
            for (int j = i+1; j < n; j++) {
                if (h[j] >= height) {
                    temp++;
                } else {
                    break;
                }
            }
            if (temp > widest) {
                widest = temp;
            }
        }
    }
    return widest;
}

int main() {
    int n, highest, area = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    highest = find_highest(h, n);
    for (int i = 1; i <= highest; i++) {
        int temp_area = i*find_widest(h, n, i);
        if (temp_area > area) {
            area = temp_area;
        }
    }
    cout << area;
    system("pause");
    return 0;
}