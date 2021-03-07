class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= p.length(); j++) {
                if (j == 0) {
                    // pattern_len is zero
                    dp[i][j] = i == 0;
                } else {
                    if (p[j - 1] != '*') {
                        if (i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                            dp[i][j] = dp[i - 1][j - 1];
                        // else f[i][j] = false; // Note: default is false
                    } else {
                        if (j >= 2) {
                            // dp[i][j] |= dp[i][j - 2]; // error ???
                            dp[i][j] = dp[i][j - 2] | dp[i][j];   // c* -> null
                            
                            // check
                            if (i >= 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                                dp[i][j] = dp[i - 1][j] | dp[i][j];
                            }
                        }
                        // other case: dp[i][j] = false; default
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
