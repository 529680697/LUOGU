#include "iostream"
#include <string.h>
#include <math.h>

using namespace std;

int a[1000000];

int main(){
    int n, num = 0;
    cin >> n;
    //memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        temp = abs(temp);
        a[temp]++;
    }
    for (int i = 0; i < 1000000; i++){
        if (a[i] == 2) {
            num++;
        }
    }
    cout << num << endl;
    //system("pause");
    return 0;
}