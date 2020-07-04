#include <iostream>

using namespace std;

int main(){
    int k, m;
    bool flag = false;
    cin >> k;
    m = k;
    while (!flag) {
        m++;
        int num = 0;
        for (int i = 0; i < k; i++) {
            num = (num + m - 1) % (2*k-i);
            if (num < k) break;
            if (i == k-1) flag = true;
        }
    }
    cout << m << endl;
    system("pause");
    return 0;
}