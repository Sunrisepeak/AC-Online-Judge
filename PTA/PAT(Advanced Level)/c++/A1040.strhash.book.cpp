#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

const LL P = 10000000 + 19;
const LL MOD = 1000000000 + 7;

vector<LL> pPow, H1, H2;
string s;

void initPPow() {
    pPow[0] = 1;
    for (int i = 1; i < pPow.size(); i++) {
        pPow[i] = (pPow[i - 1] * P) % MOD;
    }
}

void calH(vector<LL> &H, const string &str) {
    H[0] = str[0];
    for (int i = 1; i < str.length(); i++) {
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

LL subStrH(const vector<LL> &H, int i, int j) {
    if (i == 0) return H[j];
    return ((H[j] - H[i - 1] * pPow[j - i + 1]) % MOD + MOD) % MOD;
}

/**
 *  Note: 
 *      [l....r..i]  -->  [i - (l + r)/2 ....i.... i + (l + r)/2]
 *  [i - r..i..i + r] ---> binarySearch obj --> round-len = mid (0, r)
 *  @return: half-lenght of symmetric string
*/
int binarySearch(int l, int r, int len, int i, int isEven) {
    while(l < r) {
        int mid = (l + r) / 2;
        int H1L = i - mid + isEven, H1R = i;
        int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + isEven);
        int hashL = subStrH(H1, H1L, H1R);
        int hashR = subStrH(H2, H2L, H2R);
        if (hashL != hashR) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int main() {
    getline(cin, s);
    pPow.resize(s.length() + 10);
    initPPow();             // forgive init: [spend 1.5h]
    H1.resize(s.length());
    H2.resize(s.length());
    calH(H1, s);
    reverse(s.begin(), s.end());
    calH(H2, s);
    int ans = 0;
    //odd-len
    for (int i = 0; i < s.length(); i++) {
        //maxLen is most half-len of sym-str
        int maxLen = min(i, (int)s.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, s.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    //even-len
    for (int i = 0; i < s.length(); i++) {
        int maxLen = min(i + 1, (int)s.length() - i - 1) + 1;
        int k = binarySearch(0, maxLen, s.length(), i, 1);
        ans = max(ans, k * 2);
    }
    cout << ans;
    return 0;
}