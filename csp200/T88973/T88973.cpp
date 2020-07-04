#include <iostream>

using namespace std;

struct ball{
    int location;
    int velocity;
}all_ball[101];

void judge_collide(struct ball * all_ball, int n, int l) {
    for (int i = 0; i < n; i++) {
        if (all_ball[i].location == 0 || all_ball[i].location == l) {
            all_ball[i].velocity = -all_ball[i].velocity;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (all_ball[i].location == all_ball[j].location) {
                all_ball[i].velocity = -all_ball[i].velocity;
                all_ball[j].velocity = -all_ball[j].velocity;
            }
        }
    }
}

int main(){
    int n, l, t;
    cin >> n >> l >> t;
    for (int i = 0; i < n; i++) {
        cin >> all_ball[i].location;
        if (all_ball[i].location != l) {
            all_ball[i].velocity = 1;
        } else {
            all_ball[i].velocity = -1;
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            all_ball[j].location += all_ball[j].velocity;
        }
        judge_collide(all_ball, n, l);
    }
    for (int i = 0; i < n; i++) {
        cout << all_ball[i].location << ' ';
    }
    system("pause");
    return 0;
}