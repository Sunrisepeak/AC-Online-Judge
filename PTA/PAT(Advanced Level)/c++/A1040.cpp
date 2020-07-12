#include <iostream>
#include <string>

using namespace std;
// [i][j]: Is i -> j symmetric?
bool dp[1001][1001] = { { false } };

int main() {
    string str;
    getline(cin, str);
    int ans = 1;    // small-len
    // set border [length: 1 and 2]
    for (int i = 0; i < str.length(); i++) {
        dp[i][i] = true;
        if (i < str.length() - 1) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                ans = 2;
            }
        }
    }
    // solve sub-problem
    for (int subStrLen = 3; subStrLen <= str.length(); subStrLen++) {
        for (int start = 0; start + subStrLen - 1 < str.length(); start++) {
            int end = start + subStrLen - 1;
            if (str[start] == str[end] && dp[start + 1][end - 1]) {
                dp[start][end] = true;
                ans = subStrLen;
            }
        }
    }
    cout << ans;
    return 0;
}