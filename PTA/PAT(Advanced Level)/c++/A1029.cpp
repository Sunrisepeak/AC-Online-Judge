#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
vector<LL> s1, s2;

int main() {
    LL N1, N2;
    ios::sync_with_stdio(0); 
    cin >> N1;
    LL input;
    for (int i = 0; i < N1; i++) {
        cin >> input;
        s1.push_back(input);
    }
    cin >> N2;
    for (int i = 0; i < N2; i++) {
        cin >> input;
        s2.push_back(input);
    }
    LL mid = (N1 + N2 + 1) / 2;
    LL p1 = 0, p2 = 0, ans = -1;
    bool flag = true;
    while (p1 < s1.size() && p2 < s2.size()) {
        if (s1[p1] <= s2[p2]) {
            ans = s1[p1++];
        } else {
            ans = s2[p2++];
        }
        //cout << mid << "= mid-pp = " << p1 + p2 << endl;
        if (mid == p1 + p2) {
            flag = false;
            break;
        }
    }
    while (flag && p1 < s1.size()) {
        ans = s1[p1++];
        if (mid == p1 + p2) {
            flag = false;
            break;
        }
    }
    while (flag && p2 < s2.size()) {
        ans = s2[p2++];
        if (mid == p1 + p2) {
            break;
        }
    }
    cout << ans;
    return 0;
}
