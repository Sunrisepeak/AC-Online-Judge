#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Num {
    int num;
    bool left_ok{ false };
};

vector<Num> nums;
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    int N, flag;
    Num input;
    cin >> N;
    cin >> input.num;
    input.left_ok = true;
    flag = input.num;
    nums.push_back(input);
    for (int i = 1; i < N; i++) { //left -> right
        input.left_ok = false;
        cin >> input.num;
        if (flag < input.num) { //flag is left side max_num of input.num
            input.left_ok = true;
            flag = input.num;
        }
        nums.push_back(input);
    }
    if (nums[N - 1].left_ok) {
        ans.push_back(nums[N - 1].num);
    }
    flag = nums[N - 1].num; //flag is right side mix_num
    for (int i = N - 2; i >= 0; i--) {  //left <- right
        if (flag > nums[i].num) {
            if (nums[i].left_ok) {
                ans.push_back(nums[i].num);
            }
            flag = nums[i].num;
        }
    }
    if (ans.empty()) {
        cout << "0" << endl << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl << ans[0];
    for (auto it = ans.begin() + 1; it != ans.end();) {
        cout << " " << *it++; 
    }
    return 0;
}
