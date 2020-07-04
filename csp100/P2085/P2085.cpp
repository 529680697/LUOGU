#include <iostream>

using namespace std;

struct func {
    int a, b, c;
}function[10001];

int heap[10001];
// int from[10001];
int step[10001];

int find_min(int *heap, int n){
    int min = 1;
    for (int i = 2; i <= n; i++)
    {
        if(heap[min] > heap[i]) {
            min = i;
        }
    }
    return min;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> function[i].a
            >> function[i].b
            >> function[i].c;
    }
    for (int i = 1; i <= n; i++)
    {
        heap[i] = function[i].a + function[i].b + function[i].c;
        //from[i] = i;
        step[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int min = find_min(heap, n);
        cout << heap[min] << ' ';
        step[min]++;
        heap[min] = function[min].a*step[min]*step[min] + function[min].b*step[min] + function[min].c;
    }
    //system("pause");
    return 0;
}