#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> flag1(10), flag2(10);

string double_nums(const string &n) {
    string temp = "";
    int carry = 0;
    for (int i = n.length() - 1; i >= 0; i--) {
        int d_num = 2 * (n[i] - '0') + carry;
        carry = d_num / 10;
        int r = d_num % 10;
        temp = to_string(r) + temp;
    }
    if (carry != 0) {
        temp = to_string(carry) + temp;
    }
    return temp;
}

int main() {
    string nums;
    cin >> nums;
    for (auto v : nums) {
        flag1[v - '0']++;
    }
    string d_nums = double_nums(nums);
    for (auto v : d_nums) {
        flag2[v - '0']++;
    }
    if (flag1 == flag2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << d_nums;
    return 0;
}
