#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n + 1, 0);
        /* When i < 4, dp[i] = i is max. Note dp[x1] * dp[x2], dp[x] can equal itself.
         * Becase of it have partition once.
         */
        dp[0] = 0; dp[1] = 1;
        dp[2] = 2; dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                int product = dp[j] * dp[i - j];
                if (dp[i] < product) dp[i] = product;
            }
        }
        return dp[n];
    }
};

int main() {
    for (int i = 1; i <= 10; i++)
	cout << Solution().cuttingRope(i) << endl;
    return 0;
}
