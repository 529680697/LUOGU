#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int n;
int port_ip[5];
char str[1000005][20];

struct IP
{
    unsigned int i;
    int l;
    bool f; //ָʾ���Ƿ��Ƴ�
} ip[1000005];

void to_ip(string i, int num) //��IPǰ׺ת��Ϊ��׼��
{
    if (i.find("/") == string::npos) //IPΪʡ�Գ�����
    {
        int port_ip[5];
        memset(port_ip, -1, sizeof(port_ip));
        sscanf(i.c_str(), "%d.%d.%d.%d", &port_ip[0], &port_ip[1], &port_ip[2], &port_ip[3]);
        //printf("%d %d %d %d\n", port_ip[0], port_ip[1], port_ip[2], port_ip[3]);
        ip[num].i += port_ip[0];
        ip[num].l = 8;
        for (int j = 1; j < 4; j++)
        {
            if (port_ip[j] == -1)
            {
                ip[num].i <<= 8;
            }
            else
            {
                ip[num].i <<= 8;
                ip[num].i += port_ip[j];
                ip[num].l += 8;
            }
        }
    }
    else
    {
        int length = i.length() - 1;
        ip[num].l = i[length] - '0';
        length--;
        if (i[length] != '/')
        {
            ip[num].l += 10 * (i[length] - '0');
        }
        //int pos = i.find("/");
        //string t_i = i.substr(0, pos);
        //cout << t_i << endl;
        memset(port_ip, -1, sizeof(port_ip));
        sscanf(i.c_str(), "%d.%d.%d.%d", &port_ip[0], &port_ip[1], &port_ip[2], &port_ip[3]);
        //printf("%d %d %d %d\n", port_ip[0], port_ip[1], port_ip[2], port_ip[3]);
        ip[num].i += port_ip[0];
        //ip[num].l = atoi(i.substr(i.find("/") + 1).c_str());
        //cout << ip[num].l << endl;
        for (int j = 1; j < 4; j++)
        {
            if (port_ip[j] == -1)
            {
                ip[num].i <<= 8;
            }
            else
            {
                ip[num].i <<= 8;
                ip[num].i += port_ip[j];
            }
        }
    }
}

inline bool a_U_b(struct IP a, struct IP b)
{
    if (((a.i ^ b.i) >> (32 - a.l)) == 1)
        return true;
    else
        return false;
}

bool cmp(struct IP i1, struct IP i2)
{
    return i1.i == i2.i ? i1.l < i2.l : i1.i < i2.i;
}

int main()
{
    char s[30];
    string s1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s1 = str[i];
        to_ip(s1, i);
    }

    sort(ip, ip + n, cmp);
    for (int j = 0; j < n - 1;) //��С����ϲ�
    {
        if (!ip[j].f)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (!ip[k].f && (ip[j].i & (0xffffffff << (32 - ip[j].l))) == (ip[k].i & (0xffffffff << (32 - ip[j].l))))
                {
                    ip[k].f = true; //�����Ƴ���IP
                }
                else
                {
                    j = k;
                    break;
                }
            }
        }
    }
    for (int j = 0; j < n - 1;) //ͬ���ϲ�
    {
        if (!ip[j].f)
        {
            int k = j + 1;
            while (k < n && ip[k].f) //Ѱ����һ��δ�Ƴ���Ԫ��
                k++;
            if (k != n) //�ҵ���һ��δ�Ƴ���Ԫ��
            {
                if (ip[j].l == ip[k].l && a_U_b(ip[j], ip[k])) //ǰ׺��ͬ�Ҷ��߲������Ժϲ�
                {
                    ip[j].l--;
                    ip[k].f = true;
                }
                else
                {
                    j++;
                    continue;
                }
            }
            else //��������һ��Ԫ����
            {
                break;
            }
            int l = j - 1;
            while (l >= 0 && ip[l].f) //�ҵ�ǰһ��δ�Ƴ���Ԫ��
                l--;
            if (l >= 0) //����ǰһ��δ�Ƴ���Ԫ��
            {
                j = l;
            }
        }
        else
        {
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!ip[i].f)
        {
            printf("%d.%d.%d.%d/%d\n", (ip[i].i & 0xff000000) >> 24,
                   (ip[i].i & 0x00ff0000) >> 16, (ip[i].i & 0x0000ff00) >> 8,
                   (ip[i].i & 0x000000ff), ip[i].l);
        }
    }
    return 0;
}