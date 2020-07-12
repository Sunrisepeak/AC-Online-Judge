#include <iostream>

using namespace std;

int main() {
    int N, sum { 0 }, firNum, maxSSum { 0 }, ansFirNum, ansEndNum, temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        // set i == 0 for save firNum
        if ((sum <= 0 && temp >= 0) || i == 0) {
            sum = 0;
            firNum = temp;
        }
        sum += temp;
        if (sum > maxSSum) {    // update ans
            maxSSum = sum;
            ansFirNum = firNum;
            ansEndNum = temp;
        }
    }
    if (maxSSum == 0 && firNum < 0) {
        cout << maxSSum << " " << firNum << " " << temp;
    } else 
        cout << maxSSum << " " << ansFirNum << " " << ansEndNum;
    return 0;
}

/**
 * note:
    * input:
    *      -1 -2 0 -4
    * output:
    *          0 0 0
*/