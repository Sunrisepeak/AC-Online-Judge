#include <iostream>

using namespace std;

int N, V;

void pArr(const int* const &a) {
    for (int i = 0; i <= V; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int w[100], c[100], dp[100] { 0 };
    cin >> N >> V;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    pArr(dp);
    for (int i = 0; i < N; i++) {
        for (int v = V; v >= w[i]; v--) {               // dp[v - w[i]] equal dp[i - 1][v - w[i]]
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);    // dp[v] equal d[i - 1][v]
            //cout << "[debug]: " << dp[v] << "-" << v << ":" << w[i] << endl;
        }
        pArr(dp);
    }
    return 0;
}
/**
 * knapsack: 01
 * 
 * 
test data:
        5 8
        3 5 1 2 2
        4 5 2 1 3
*/