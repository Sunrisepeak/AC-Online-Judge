#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 10010
#define maxv 110

using namespace std;

bool choice[maxn][maxv] = { false };

bool cmp(int A, int B) {
    return A > B;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> coins(N + 10), dp(M + 10, 0);
    for (int i = 1; i <= N; i++) {
        cin >> coins[i];
    }
    sort(coins.begin() + 1, coins.begin() + N + 1, cmp);    // [1]for the smallest sequence
    // dp[i][v]: 0 ~ i opt-choice when capacity is to equal v
    for (int i = 1; i <= N; i++) {
        for (int v = M; v >= coins[i]; v--) {
            if (dp[v] <= dp[v - coins[i]] + coins[i]) {     // [2]for the smallest sequence
                dp[v] = dp[v - coins[i]] + coins[i];
                choice[i][v] = 1;
            }
        }
    }
    if (dp[M] != M) cout << "No Solution";
    else {
        int k = N, v = M;
        vector<int> ans;
        while(k > 0) {
            if (choice[k][v] == 1) {
                ans.push_back(coins[k]);
                v -= coins[k];
            }
            k--;
        }
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
    }
    return 0;
}

/**
 * M --> capacity
 * face value of coins  -->  weight of goods
 * 
test data:
    8 9
    5 9 3 7 2 8 4 1
*/