class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> dupNums(nums);
        sort(dupNums.begin(), dupNums.end());

        int left = 0, right = dupNums.size() - 1;
        while (dupNums[left] + dupNums[right] != target)
        {
            if (dupNums[left] + dupNums[right] < target) ++left;
            else if (dupNums[left] + dupNums[right] > target) --right;
        }
        return vector<int> {left, right};
    }
};