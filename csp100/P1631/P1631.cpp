#include <iostream>

using namespace std;

int a[100001];
int b[100001];
int heap[100001];
int from[100001];
int step[100001];

void swap(int x, int y){
    int k =heap[x];
    heap[x] = heap[y];
    heap[y] = k;
    k = from[y];
    from[y] = from[x];
    from[x] = k;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++){
        heap[i] = a[i] + b[1];
        from[i] = i;  //堆中第i个所在的列数
        step[i] = 1;  //第i列进行到的行数
    }
    for (int i = 1; i <= n; i++){
        cout << heap[1] << ' ';
        step[from[1]]++;
        heap[1] = a[from[1]]+b[step[from[1]]];
        for (int i = 1; i <= n; i++){
            if (heap[i] > heap[i+1]){
                swap(i, i+1);
            } else break;
        }
    }
    //system("pause");
    return 0;
}