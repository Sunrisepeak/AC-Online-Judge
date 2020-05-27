#include <iostream>
#include <vector>

using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> fac, ans, temp;

int power(int x) {
    int ans = 1;
    for (int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}

void init() {
    int i = 0, temp = 0;
    while(temp <= n) {
        fac.push_back(temp);
        temp = power(++i);
    }
}

/**
 * @index:
 * @nowK:
 *   fac:87654321
 *      *-------> x
 *      |
 *      v   y
*/

void DFS(int index, int nowK, int sum, int facSum) {
    if (sum == n && nowK == k) {
        if (facSum > maxFacSum) {
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if (sum > n || nowK > k) return;
    if (index - 1 >= 0) {
        temp.push_back(index);  // push y-branch of choose
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        temp.pop_back();        // pop
        DFS(index - 1, nowK, sum, facSum);  // x-branch
    }
}

int main() {
    cin >> n >> k >> p;
    init();
    DFS(fac.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        cout << "Impossible";
    } else {
        cout << n << " = " << ans[0] << "^" << p;
        for (int i = 1;i < ans.size(); i++) {
            cout << " + " << ans[i] << "^" << p;
        }
    }
    return 0;
}