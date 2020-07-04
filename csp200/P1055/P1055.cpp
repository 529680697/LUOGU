#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a[10], s, sum = 0;
    a[0] = getchar()-'0';
    getchar();
    for (int i = 1; i < 4; i++) {
        a[i] = getchar()-'0';
    }
    getchar();
    for (int i = 4; i < 9; i++) {
        a[i] = getchar()-'0';
    }
    getchar();
    s = getchar();
    for (int i = 0; i < 9; i++)
    {
        sum += a[i]*(i+1);
    }
    sum = sum % 11;
    if (s == 'X') {
        if (sum == 10){
            cout << "Right";
            system("pause");
            return 0;
        } else {
            cout << a[0] <<'-';
            for (int i = 1; i < 4; i++) {
                cout << a[i];
            }
            cout << '-';
            for (int i = 4; i < 9; i++) {
                cout << a[i];
            }
            cout << '-' << sum;
            system("pause");
            return 0;
        }
    } else {
        if (sum == 10) {
            cout << a[0] <<'-';
            for (int i = 1; i < 4; i++) {
                cout << a[i];
            }
            cout << '-';
            for (int i = 4; i < 9; i++) {
                cout << a[i];
            }
            cout << "-X";
            system("pause");
            return 0;
        } else if (sum == s-'0') {
            cout << "Right";
            system("pause");
            return 0;
        } else {
            cout << a[0] <<'-';
            for (int i = 1; i < 4; i++) {
                cout << a[i];
            }
            cout << '-';
            for (int i = 4; i < 9; i++) {
                cout << a[i];
            }
            cout << '-' << sum;
            system("pause");
            return 0;
        }
    }
    return 0;
}