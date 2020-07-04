#include <iostream>
#include <stdlib.h>

using namespace std;

int a[1000000];

int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int n, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    qsort(a, n, sizeof(int), comp);
    for (int i = 0; i < n-1; i++){
        if (a[i+1]-a[i] == 1){
            num++;
        }
    }
    cout << num << endl;
    //system("pause");
    return 0;
}