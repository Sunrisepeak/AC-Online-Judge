#include <iostream>
#include <cmath>

using namespace std;
using LL = long long;

int main() {
    LL N;
    cin >> N;
    LL ansI = 0, ansLen = 0;
    for (LL i = 2; i <= sqrt(N); i++) {
        LL temp = 1, j = i;
        while (1) {
            temp *= j;
            if (N % temp != 0) {
                break;
            }
            if (j - i + 1 > ansLen) {
                ansI = i;
                ansLen = j - i + 1;
            }
            j++;
        }
    }

    if (ansLen == 0) {
        cout << "1" << endl << N;
    } else {
        cout << ansLen << endl << ansI;
        for (LL i = 1; i < ansLen; i++) {
            cout << " " << ansI + i;
        }
    }
    return 0;
}
