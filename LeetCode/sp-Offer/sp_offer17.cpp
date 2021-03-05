class Solution {
public:
    vector<int> printNumbers(int n) {
        int size = static_cast<int>(pow(10, n) - 1);
        ans.resize(size);
        dfs(string(n, '0'), 0, n);
        return ans;
    }
private:
    vector<int> ans;
    int cnt = 0;
    void dfs(string s, int index, int len) {
        if (index == len) {
            int num = stoi(s);
            if (num > 0)    // not good
                ans[num -1] = num;
        } else {
            while (s[index] <= '9') {
                dfs(s, index + 1, len);
                s[index]++;
            }
        }
    }
};
