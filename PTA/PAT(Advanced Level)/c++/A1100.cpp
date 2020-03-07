#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, string> money {
    {0, "tret"}, {1, "jan" }, {2, "feb"}, {3, "mar" },
    {4, "apr"}, {5, "may" }, {6, "jun"}, {7, "jly" },
    {8, "aug"}, {9, "sep" }, {10, "oct"}, {11, "nov" },
    {12, "dec"},

    {1 * 13, "tam" }, {2 * 13, "hel"}, {3 * 13, "maa" }, {4 * 13, "huh"},
    {5 * 13, "tou" }, {6 * 13, "kes"}, {7 * 13, "hei" }, {8 * 13, "elo"},
    {9 * 13, "syy" }, {10 * 13, "lok"}, {11 * 13, "mer" }, {12 * 13, "jou"}
};

string toMars(int n) {
    string ans = "";
    if (n % 13 != 0 && n >= 13) {
        int r = n % 13;
        ans = money[n - r] + " " + money[r];
    } else {
        ans = money[n];
    }
    return ans;
}

int toEarth(const vector<string> &m) {
    int ans = 0;
    for (int i = 0; i < m.size(); i++) {
        int t = 0;
        for (auto c : money) {
            if (c.second == m[i]) {
                t = c.first;
            }
        }
        ans += t;
    }
    return ans;
}

int main() {
    int N;
    string temp;
    cin >> N;
    getline(cin, temp);
    for (int i = 0; i < N; i++) {
        getline(cin, temp);
        if (isdigit(temp[0])) {
            cout << toMars(stoi(temp));
        } else {
            vector<string> v;
            int begin{ 0 }, end{ 0 };
            while (end < temp.size()) {
                for (; end < temp.size(); end++) {
                    if (temp[end] == ' ') {
                        break;
                    }
                }
                v.push_back(temp.substr(begin, end - begin));
                begin = end + 1;
                end = begin;
            }
            cout << toEarth(v);
        }
        cout << endl;
    }
    return 0;
}