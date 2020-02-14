#include <iostream>
#include <cstdio>

using LL = long long;

struct Fraction {
    LL up, down;
};

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    LL N;
    Fraction sum, temp;
    sum.up = 0;
    sum.down = 1;
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld/%lld", &temp.up, &temp.down);
        sum.up = sum.up * temp.down + sum.down * temp.up;
        sum.down = sum.down * temp.down;
        if (sum.down < 0) {
            sum.down = -sum.down;
            sum.up = -sum.up;
        }
        if (sum.up == 0) {
            sum.down = 1;
        } else {
            LL d = gcd(abs(sum.up), abs(sum.down));
            sum.up /= d;
            sum.down /= d;
        }
    }

    if (sum.down == 1) {
        printf("%lld\n", sum.up);
    } else if (abs(sum.up) > sum.down) {
        printf("%lld %lld/%lld\n", sum.up / sum.down, abs(sum.up) % sum.down, sum.down);

    } else {
        printf("%lld/%lld\n", sum.up, sum.down);
    }
    return 0;
}
