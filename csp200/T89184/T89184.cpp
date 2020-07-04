#include <iostream>

using namespace std;

int s_3(int t) {
    int a = (t*100 - 3500*3)/97;
    if (3500 < a && a <= 5000) {
        return a;
    }
    return 0;
}

int s_10(int t) {
    int a = (t*10-4550)/9;
    if (5000 < a && a <= 8000) {
        return a;
    }
    return 0;
}

int s_20(int t) {
    int a = (5*t-6275)/4;
    if (8000 < a && a <= 12500) {
        return a;
    }
    return 0;
}

int s_25(int t) {
    int a = (4*t-7520)/3;
    if (12500 < a && a <= 38500) {
        return a;
    }
    return 0;
}

int s_30(int t) {
    int a = (10*t-38050)/7;
    if (38500 < a && a <= 58500) {
        return a;
    }
    return 0;
}

int s_35(int t) {
    int a = (t*20-134600)/13;
    if (58500 < a && a <= 83500) {
        return a;
    }
    return 0;
}

int s_45(int t) {
    int a = (20*t-301600)/11;
    if (83500 < a) {
        return a;
    }
    return 0;
}

int main(){
    int t, s;
    cin >> t;
    if (t<=3500){
        cout << t;
        return 0;
    } else if ((s = s_3(t))) {
        cout << s;
        return 0;
    } else if ((s = s_10(t))) {
        cout << s;
        return 0;
    } else if ((s = s_20(t))) {
        cout << s;
        return 0;
    } else if ((s = s_25(t))) {
        cout << s;
        return 0;
    } else if ((s = s_30(t))) {
        cout << s;
        return 0;
    } else if ((s = s_35(t))) {
        cout << s;
        return 0;
    } else if ((s = s_45(t))) {
        cout << s;
        return 0;
    }
    return 0;
}