#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, P;
    cin >> N >> P;
    vector<long long> nums;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end());
    int max_num = 0;
    for (int i = 0; i < nums.size(); i++) {
        int skip = (nums.size() - i) / 2 + 1;
        int j = i;
        while (skip > 0) {
            while (j < nums.size() && nums[j] <= nums[i] * P) {
                j += skip;
            }
            j -= skip;  //recover
            skip /= 2;
        }
        if(j - i + 1> max_num) {
            max_num = j - i + 1;
        //    cout << max_num << endl;
        }
    }
    cout << max_num;
    return 0;
}
