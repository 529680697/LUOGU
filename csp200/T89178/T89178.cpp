#include <iostream>
#include <algorithm>

using namespace std;

int key_box[1001];
struct use_key {
    int w;
    int s;
    int c;
}use[1001];

bool cmp(struct use_key x, struct use_key y) {
    return x.w < y.w;
}

void back_key(int *key_box, int key, int n) {
    for (int i = 1; i <= n; i++) {
        if (key_box[i] == 0) {
            key_box[i] = key;
            break;
        }
    }
}

void get_key(int *key_box, int key, int n) {
    for (int i = 1; i <= n; i++) {
        if (key_box[i] == key) {
            key_box[i] = 0;
            break;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> use[i].w >> use[i].s >> use[i].c;
    }
    sort(use+1, use+k+1, cmp);
    for (int i = 1; i <= n; i++) {
        key_box[i] = i;
    }
    for (int i = 1; i < 10101; i++) {
        for (int j = 1; j <= k; j++) {
            if (use[j].s+use[j].c == i) {
                back_key(key_box, use[j].w, n);
            }
        }
        for (int j = 1; j <= k; j++) {
            if (use[j].s == i) {
                get_key(key_box, use[j].w, n);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << key_box[i] << ' ';
    }
    system("pause");
    return 0;
}