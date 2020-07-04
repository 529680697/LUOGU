#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

struct man {
    int num;
    int height;
    int wealth;
    int appearance;
    int age;
}all_man;

struct cmp {
    bool operator() (const man &x, const man &y) const {
        if (x.appearance != y.appearance)
            return y.appearance < x.appearance;
        if (x.height != y.height)
            return y.height < x.height;            
        if (x.wealth != y.wealth)
            return y.wealth < x.wealth;                
        return x.age < y.age;
    }
};

bool cmp1(const man x, const man y){
    if (x.appearance != y.appearance)
        return y.appearance < x.appearance;
    if (x.height != y.height)
        return y.height < x.height;            
    if (x.wealth != y.wealth)
        return y.wealth < x.wealth;                
    return x.age < y.age;
}

priority_queue <man, vector<man>, cmp> q;

int input()
{
	char ch = ' ';
	while (ch<'0' || ch>'9')ch = getchar();
	int x = 0;
	while (ch <= '9'&&ch >= '0')x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int main(){
    int n, m;
    stack <int> s;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        all_man.height = input();
        all_man.wealth = input();
        all_man.appearance = input();
        all_man.age = input();
        all_man.num = i;
        q.push(all_man);
    }
    for (int i = m+1; i <= n; i++) {
        all_man.height = input();
        all_man.wealth = input();
        all_man.appearance = input();
        all_man.age = input();
        all_man.num = i;
        if (cmp1(all_man, q.top())) {
            q.pop();
            q.push(all_man);
        }
    }
    for (int i = 0; i < m; i++){
        s.push(q.top().num);
        q.pop();
    }
    for (int i = 0; i < m; i++){
        cout << s.top() << ' ';
        s.pop();
    }
    //system("pause");
    return 0;
}