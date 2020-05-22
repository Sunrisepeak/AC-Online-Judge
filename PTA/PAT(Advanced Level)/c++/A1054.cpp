/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-19 17:53:15 
 * @Last Modified by:   SPeak Shen 
 * @Last Modified time: 2020-05-19 17:53:15 
 */

// run time: 63ms
#include <iostream>

using LL = long long;
using namespace std;

LL a[2][480001]{ 0 };

int exitsCount(LL num, LL maxPos) {
    for (int i = maxPos; i >= 0; i--) {
        if (a[0][i] == num) {
            return a[1][i];
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    LL N, M;
    cin >> N >> M;
    LL max = 0, ans;
    for (int i = 0; i < N * M; i++) {
        cin >> a[0][i];
        int count = exitsCount(a[0][i], i - 1);
        a[1][i] = count + 1;
        if (a[1][i] > max) {
            ans = a[0][i];
            max = a[1][i];
        }
        
        if (max > (N * M) / 2)  // unless judge case 2: time limit Exceeded
            break;   
    }
    cout << ans << endl;
    return 0;
}