#include <iostream>
#include <memory.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define max_num 1000001

struct quary{
    int l, r;
    int pos;
}ask[max_num];

int num[max_num];  //存放项链数
int ans[max_num];  //存放每次查询结果
int flag[max_num];  //r前最靠右出现的位置
int tree[max_num];  //树状数组
int N, M;

int input()
{
	char ch = ' ';
	while (ch<'0' || ch>'9')ch = getchar();
	int x = 0;
	while (ch <= '9'&&ch >= '0')x = x * 10 + ch - '0', ch = getchar();
	return x;
}

bool cmp(quary x, quary y) {
    return x.r < y.r;
}

int lowbit(int x) {
    return x&(-x);
}

int sum(int k) {
    int ans = 0;
    while (k != 0) {
        ans += tree[k];
        k -= lowbit(k);
    }
    return ans;
}

void add(int n, int increase) {
    while (n <= N) {
        tree[n] += increase;
        n += lowbit(n);
    }
}

int main() {
    N = input();
    for (int i = 1; i <= N; i++) {
        num[i] = input();
    }
    M = input();
    for (int i = 1; i <= M; i++) {
        ask[i].l = input();
        ask[i].r = input();
        ask[i].pos = i;
    }
    sort(ask+1, ask+1+M, cmp);
    int nex = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = nex; j <= ask[i].r; j++) {
            if (flag[num[j]]) {
                add(flag[num[j]], -1);
            }
            add(j, 1);
            flag[num[j]] = j;
        }
        nex = ask[i].r + 1;
        ans[ask[i].pos] = sum(ask[i].r) - sum(ask[i].l-1);
    }
    for (int i = 1; i <= M; i++) {
        cout << ans[i] << endl;
    }
    
    system("pause");
    return 0;
}