#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N), dp(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // set border
    dp[0] = arr[0];
    // solve sub-problem
    for (int i = 1; i < N; i++) {
        if (dp[i - 1] > 0) {
            dp[i] = dp[i - 1] + arr[i];
        } else {
            dp[i] = arr[i];
        }
    }

    int index = 0, sum = -1;
    for (int i = 0; i < N; i++) {
        if (dp[i] > sum) {
            sum = dp[i];
            index = i;
        }
    }
    // output1: maxSSum
    if (sum > 0) {
        cout << sum;
    } else {
        cout << "0";
    }
    // output2: firIndex-Num of subsequence
    int firIndex;
    for (firIndex = index - 1; firIndex >= 0; firIndex--) {
        if (dp[firIndex] <= 0) {
            break;
        }
    }
    cout << " " << arr[firIndex + 1];
    // output3: endIndex-Num of subsequence
    if (sum < 0) cout << " " << arr[N - 1];
    else cout << " " << arr[index];
    return 0;
}