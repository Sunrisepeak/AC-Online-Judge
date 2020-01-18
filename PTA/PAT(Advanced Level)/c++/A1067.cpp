#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> nums;
int ans = 0;
int k = 1;


bool swap_zero()
{
    if (nums[0] == 0) {    
        for (; k < nums.size(); k++) {  // Note: time limit
            if (k != nums[k]) {
                swap(nums[k], nums[0]);
                ans++;
                break;
            }
        }
        if(nums[0] == 0)
            return false;
    }
    while (nums[0] != 0) {
        swap(nums[0], nums[nums[0]]);
        ans++;
    }
    return true;
}

int main()
{
    int N, temp, zero_pos = -1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    while (swap_zero());
    cout << ans;
    return 0;
}