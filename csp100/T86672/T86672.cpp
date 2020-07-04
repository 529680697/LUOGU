#include <iostream>
#include <stdlib.h>

using namespace std;

int a[1000001];

int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}

int main(){
    int n, min, count;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    qsort(a, n, sizeof(int), comp);
    min = a[0];
    count = 1;
    int i = 0;
    while (i < n)
    {
        int j = i+1;
        int temp_count = 1;
        while (a[j] == a[i] && j < n) {
            temp_count++;
            j++;
        }
        if (count < temp_count || (count == temp_count && a[j-1] < min)) {
            count = temp_count;
            min = a[j-1];
        }
        i = j;
    }
    cout << min;
    //system("pause");
    return 0;
}