#include <iostream>
#include <memory.h>

using namespace std;

int luck_one(int n, int k){
    bool flag[100000];
    memset(flag, 0, 100000*sizeof(bool));
    int j = 0;
    for (int i = 0; i < n-1; i++) {
        int num = 0;
        while (num < k) {
            if (!flag[j]) {
                num++;
            }
            j = (j+1) % n;
        }
        flag[(j+n-1) % n] = 1;
    }
    for (j = 0; j < n; j++)
    {
        if (!flag[j]) {
            break;
        }
    }
    return j;
}

int main(){
    int n;
    cin >> n;
    int sum = 0, last_luck, luck;
    luck = luck_one(n, 2);
    last_luck = luck;
    sum += n - 1 - luck;
    n = luck + 1;
    luck = luck_one(n, 2);
    while (luck != last_luck) {
        sum += n - 1 - luck;
        n = luck + 1;
        last_luck = luck;
        luck = luck_one(n, 2);
    }
    sum += 2 * (luck + 1);
    cout << sum;
    //system("pause");
    return 0;
}