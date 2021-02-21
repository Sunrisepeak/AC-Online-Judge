#include <iostream>
#include <array>

using namespace std;

using FMatrix = array<array<unsigned long long, 2>, 2>;

#define ZERO_MATRIX FMatrix{array<unsigned long long, 2>{0, 0}, array<unsigned long long, 2>{0, 0}}
#define E_MATRIX FMatrix{array<unsigned long long, 2>{1, 0}, array<unsigned long long, 2>{0, 1}}
#define FIB_MATRIX FMatrix{array<unsigned long long, 2>{1, 1}, array<unsigned long long, 2>{1, 0}}
#define BASE 1000000007

FMatrix operator*(const FMatrix &a, const FMatrix &b) {
    FMatrix c(ZERO_MATRIX);
    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % BASE;
    c[0][1] = (a[0][0] * b[1][0] + a[0][1] * b[1][1]) % BASE;
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % BASE;
    c[1][1] = (a[1][0] * b[1][0] + a[1][1] * b[1][1]) % BASE;
    return c;
}

class Solution {
public:

    int fib(int n) {
	// to try myFib1
        return myFib2(n);
    }

private:
    int fibValue[101] = { 0 };
    array<FMatrix, 101> mP{ 0 };

    FMatrix fmPower(FMatrix::size_type n) {
        if (n == 1) return FIB_MATRIX;
        else {
            if (mP[n] == ZERO_MATRIX)
                mP[n] = fmPower(n / 2) * fmPower(n / 2) * (n % 2 ? FIB_MATRIX : E_MATRIX);
            return mP[n];
        }
    }

    int myFib1(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else {
            if (fibValue[n] == 0)
                fibValue[n] = (myFib1(n - 1) + myFib1(n - 2)) % BASE;
           return fibValue[n];
        }
    }

    int myFib2(int n) {
        /**
         *
	 * +-			  -+
	 * | fib(n)     fib(n - 1) |    = FIB_MATRIX ^ (n - 1)
	 * | fib(n - 1) fib(n - 2) |
	 * +-		          -+
	 *
         */
        return fmPower(n - 1)[0][0];
    }
};

int main() {
    Solution s;
    cout << s.fib(99) << endl;
    return 0;
}

/**
 *
 * fib(99) % BASE = 94208912
 *
 * */
