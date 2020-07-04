#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node
{
    short height;
    int wealth;
    short appearance;
    short age;
    int order;
} node;

int judge_value(node * a, node * b);

bool shouldUp(node *father, node *child)
{
    return (judge_value(father, child) == -1);
}

void insert(node **list, node *temp_node, int n)
{
    list[n] = temp_node;
    int i = n;
    while (i && shouldUp(list[(i+1) / 2 - 1], list[i])) {
        node * swap_node = list[i];
        list[i] = list[(i+1) / 2 - 1];
        list[(i+1) / 2 - 1] = swap_node;
        i = (i+1) / 2 - 1;
    }
}

void swap(node ** list, int i) {
    node * swap_node = list[i];
    list[i] = list[(i+1) / 2 - 1];
    list[(i+1) / 2 - 1] = swap_node;
}

int judge_value(node * a, node * b) {  //判断a与b的大小，1：大于；0：相等；-1：小于
    if (a->appearance > b->appearance) {
        return 1;
    } else if (a->appearance == b->appearance) {
        if (a->height > b->height) {
            return 1;
        } else if (a-> height== b->height) {
            if (a->wealth > b->wealth) {
                return 1;
            } else if (a->wealth == b->wealth) {
                if (a->age < b->age) {
                    return 1;
                } else if (a->age == b->age) {
                    return 0;
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }
    return -1;
}

void shift_down(node ** list, int n) {
    list[0] = list[n];
    int i = 0;
    bool flag = true;
    while (i < n && flag) {
        if ((i+1) * 2 < n) {
            node * fath = list[i], *left = list[(i+1) * 2 - 1], *right = list[(i+1) * 2];
            int judge_fath_left = judge_value(fath, left);
            int judge_fath_right = judge_value(fath, right);
            int judge_left_right = judge_value(left, right);
            if (judge_fath_left == -1 && judge_fath_right == -1) {
                if (judge_left_right == 1) {
                    swap(list, (i+1) * 2 - 1);
                    i = (i+1) * 2 - 1;
                } else if (judge_left_right == 0) {
                    swap(list, (i+1) * 2 - 1);
                    i = (i+1) * 2 - 1;
                } else {
                    swap(list, (i+1) * 2);
                    i = (i+1) * 2;
                }
            } else if (judge_fath_left == -1 && judge_fath_right == 0) {
                swap(list, (i+1) * 2 - 1);
                i = (i+1) * 2 - 1;
            } else if (judge_fath_left == 0 && judge_fath_right == -1) {
                swap(list, (i+1) * 2);
                i = (i+1) * 2;
            } else if (judge_fath_left == 0 && judge_fath_right == 0) {
                swap(list, (i+1) * 2 - 1);
                i = (i+1) * 2 - 1;
            } else if (judge_fath_left == 1 && judge_fath_right == 1) {
                flag = false;
            } else if (judge_fath_left == 1 && judge_fath_right == 0) {
                swap(list, (i+1) * 2);
                i = (i+1) * 2;
            } else if (judge_fath_left == 0 && judge_fath_right == 1) {
                swap(list, (i+1) * 2 - 1);
                i = (i+1) * 2 - 1;
            } else if (judge_fath_left == 1 && judge_fath_right == -1) {
                swap(list, (i+1) * 2);
                i = (i+1) * 2;
            } else if (judge_fath_left == -1 && judge_fath_right == 1) {
                swap(list, (i+1) * 2 - 1);
                i = (i+1) * 2 - 1;
            }
        } else if ((i+1) * 2 == n) {
            node * fath = list[i], *left = list[(i+1) * 2 - 1];
            int judge_fath_left = judge_value(fath, left);
            if (judge_fath_left == 1) {
                flag = false;
            } else {
                swap(list, (i+1) * 2 - 1);
                i = (i+1) * 2 - 1;
            }
        } else {
            flag = false;
        }
    }
}


node *list[1000001];
node List[1000001];
int main()
{
    int n, k;
    cin >> n >> k;
    node *root = &List[0];

    cin >> root->height
        >> root->wealth
        >> root->appearance
        >> root->age;
    root->order = 1;
    list[0] = root;
    for (int i = 1; i < n; i++)
    {
        node *temp_node = &List[i];
        temp_node->order = i+1;
        cin >> temp_node->height
            >> temp_node->wealth
            >> temp_node->appearance
            >> temp_node->age;

    }
    for (int l = 1; l < n; ++l) {
        insert(list, &List[l], l);
    }
    for (int j = 0; j < k; j++) {
        cout << list[0]->order << " ";
        shift_down(list, n - j - 1);
    }
    //system("pause");
    return 0;
}