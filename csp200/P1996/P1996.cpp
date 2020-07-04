#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int n, m, num = 0;
    bool people[101];
    memset(people, 0, 101*sizeof(bool));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = 0; 
        while (true)
        {
            if (!people[((num + k)%n)]) {
                j++;
                if (j == m){
                    people[((num + k)%n)] = 1;
                    break;
                }
            } 
            k++;
        }
        cout << ((num + k)%n)+1 << ' ';
        num = ((num + k)%n);
    }
    system("pause");
    return 0;
}