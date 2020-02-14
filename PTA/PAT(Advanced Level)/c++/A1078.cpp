#include <iostream>
#include <cmath>

using namespace std;
bool hashTable[10010] = { false };

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int HashQuadraticPr(int index, int size) {
    int pos = index;
    for (int i = 0; i <= size / 2; i++) {
        pos = (index + i * i) % size;   // h(key) = (originKey + i * i) % size;
        if (!hashTable[pos]) {
            hashTable[pos] = true;
            return pos;
        }
    }
    return -1;
}

int main() {
    int M, N;
    cin >> M >> N;
    while (!isPrime(M)) {
        M++;
    }
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        int pos = HashQuadraticPr(input, M);
        if (pos == -1) {
            cout << "-";
        } else {
            cout << pos;
        }
        if (i < N - 1) {
            cout << " ";
        }
    }
    return 0;
}
