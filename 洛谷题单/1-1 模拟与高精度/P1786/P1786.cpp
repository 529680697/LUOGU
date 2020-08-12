#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct node
{
    string name;
    int job_num, bg, grade, id;
} bang[120];

int n, job_no[8] = {0, 0, 2, 4, 7, 25, 110, 0};
map<string, int> job2num;
string num2job[8];

bool cmp1(node a, node b)
{
    if (a.bg > b.bg)
        return true;
    else if (a.bg == b.bg)
        return a.id < b.id;
    else
        return false;
}

bool cmp2(node a, node b)
{
    if (a.job_num < b.job_num)
        return true;
    else if (a.job_num == b.job_num)
    {
        if (a.grade > b.grade)
            return true;
        else if (a.grade == b.grade)
            return a.id < b.id;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    char tmp[64];
    freopen("in.txt", "r", stdin);
    cin >> n;
    num2job[0] = "BangZhu";
    num2job[1] = "FuBangZhu";
    num2job[2] = "HuFa";
    num2job[3] = "ZhangLao";
    num2job[4] = "TangZhu";
    num2job[5] = "JingYing";
    num2job[6] = "BangZhong";
    for (int i = 0; i < 7; i++)
        job2num[num2job[i]] = i;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        bang[i].name = tmp;
        scanf("%s", tmp);
        bang[i].job_num = job2num[tmp];
        bang[i].id = i;
        cin >> bang[i].bg >> bang[i].grade;
    }
    sort(bang + 3, bang + n, cmp1);
    int bang_i = 3;
    for (int i = 2; i < 7; i++)
    {
        for (int j = 0; j < job_no[i]; j++)
        {
            if (bang_i < n)
            {
                bang[bang_i++].job_num = i;
            }
            else
            {
                sort(bang + 3, bang + n, cmp2);
                for (int i = 0; i < n; i++)
                    cout << bang[i].name << " " << num2job[bang[i].job_num] << " " << bang[i].grade << endl;
                return 0;
            }
        }
    }
    return 0;
}