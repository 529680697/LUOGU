#include <iostream>

using namespace std;

long time(long sum, long k, long t, long r, long y, long g) {
    if (k == 0) {
        return sum+t;
    } else if (k == 1) {
        long temp = sum % (r+y+g);
        if (temp <= t) {
            return sum + (t - temp);
        } else if (t <= temp && temp <= t+g) {
            return sum;
        } else if (t+g < temp && temp < t+y+g+r) {
            return sum + (t+g+y+r-temp);
        }
    } else if (k == 2) {
        long temp = sum % (r+y+g);
        if (temp < t+r) {
            return sum + (r+t-temp);
        } else if (t+r <= temp && temp <= t+r+g) {
            return sum;
        } else if(t+r+g < temp) {
            return sum + (t+r+g+y+r-temp);
        }
    } else if (k == 3) {
        long temp = sum % (r+y+g);
        if (temp <= t) {
            return sum;
        } else if (t < temp && temp < t+y+r) {
            return sum + (t+y+r-temp);
        } else if (t+y+r <= temp) {
            return sum;
        }
    }
}

int main() {
    long r, y, g, n, k, t;
    long sum = 0;
    cin >> r >> y >> g >> n;
    for (long i = 0; i < n; i++)
    {
        cin >> k >> t;
        sum = time(sum, k, t, r, y, g);
    }
    cout << sum;
    //system("pause");
    return 0;
}