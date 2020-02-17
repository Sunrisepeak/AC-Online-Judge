#include <iostream>
#include <string>
#include <algorithm> //reverse()
using namespace std;

bool is_palin_nums(string nums) {
    string temp = nums;
    reverse(nums.begin(), nums.end());
    if (temp == nums) {
        return true;
    }
    return false;
}

string bigNum__add(string n1, string n2) {
    if (n1.length() < n2.length()) { //this problem is not necessery.
        swap(n1, n2);
    }
    string temp = "";
    int carry = 0;
    int distance = n1.length() - n2.length();
    for (int i = n1.length() - 1; i >= 0; i--) {
        char c = '0';
        if (i - distance >= 0) {
            c = n2[i - distance];
        }
        int sum = n1[i] + c - '0' * 2 + carry;
        carry = sum / 10;
        int r = sum % 10;
        temp = to_string(r) + temp;
    }
    if (carry != 0) {
        temp = to_string(carry) + temp;
    }
    return temp;
}

int main() {
    string nums;
    int K;
    cin >> nums >> K;
    int step = 0;
    while (step < K && !is_palin_nums(nums)) {
        string re_nums = nums;
        reverse(re_nums.begin(), re_nums.end());
        // cout << nums << " + " << re_nums;
        nums = bigNum__add(re_nums, nums);
        //cout << " = " << nums << endl;
        step++;
    }
    cout << nums<< endl << step;
    return 0;
}
