class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> hashTable(nums.size(), false);
        int ans = 0;
        for (const auto &v : nums) {
            if (!hashTable[v]) 
                hashTable[v] = true;
            else {
                ans = v;
                break;
            }
        }
        return ans;
    }
};
