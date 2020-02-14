#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int get_decimal(string n, int radix) {
    int newNum = 0, t = 1;
    for (int i = n.length() - 1; i >= 0; i--) {
        newNum += (n[i] - '0') * t;
        t *= radix;
    }
    return newNum;
}

int reverse_num(int n, int radix) {
    string temp = "";
    while (n) {
        temp += to_string(n % radix);
        n /= radix;
    }
    int rNum = get_decimal(temp, radix);
    return rNum;
}
/*
 *              2      reverse     10
 * 23 2 :   23 --> 10111 --> 11101 --> 29
 *
 * */

int main() {
    int N, D;
    while (cin >> N && N >= 0 && cin >> D) {
        if (isPrime(N) && isPrime(reverse_num(N, D))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
