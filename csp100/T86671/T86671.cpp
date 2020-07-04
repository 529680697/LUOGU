#include <iostream>

using namespace std;

typedef struct node{
    int data;
    int num;
    struct node *next;
}Node;

void add_node(Node *root, int a) {
    Node *tp = root;
    if (tp->data == a) {
        tp->num++;
        return;
    }
    while (tp->next) {
        if (tp->next->data == a) {
            tp->next->num++;
            return;
        } else {
            tp = tp->next;
        }
    }
    tp->next = (Node *)malloc(sizeof(Node));
    tp->next->data = a;
    tp->next->num = 1;
    tp->next->next = NULL;
}

int main(){
    int n, a[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    struct node list, *root = &list;
    root->data = a[0];
    root->num = 1;
    root->next = NULL;
    for (int i = 1; i < n; i++) {
        add_node(root, a[i]);
    }
    int min = root->data;
    int count = root->num;
    while (root->next) {
        if (root->next->num > count) {
            min = root->next->data;
            count = root->next->num;
        } else if (root->next->num == count && root->next->data < min){
            min = root->next->data;
            count = root->next->num;
        }
        root = root->next;
    }
    cout << min;
    //system("pause");
    return 0;
}