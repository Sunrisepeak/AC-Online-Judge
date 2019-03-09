#include <iostream>
#include <map>
using namespace std;

map<char, int> m;
char c;

int main()
{   
    while (cin >> c)
        if (c >= 'A' && c <= 'Z')
            m[c]++;
    int Max = -1;
    for (auto i : m)
        if (i.second > Max)
            Max = i.second;//取直方图高度
    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < 26; j++)
            if (i >= Max - m[j + 'A'])//确保底在下面
                cout << "* ";
            else
                cout << "11";
        cout << endl;
    }
    for (auto i : m)
        cout << i.first << " ";
    return 0;
}