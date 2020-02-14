#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, ans = 0, pre_prime = 2;
    cin >> N;
    for (int i = 3; i <= N; i++) {
        if (isPrime(i)) {
            if (i - pre_prime == 2) {
                ans++;
            }
            pre_prime = i; 
        }
    }
    cout << ans;
    return 0;
}
