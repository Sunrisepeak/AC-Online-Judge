class Solution {
public:
    int climbStairs(int n) {
        //f(n) = f(n - 1) + f(n - 2);
        int f2 = 1, f1 = 1; // f(0), f(1)
        for (int i = 2; i <= n; i++) {
            f2 = f1 + f2;
            f1 = f2 - f1;
        }
        return f2;
    }
};

/**
 *
 * 1.recursion
 * 2.roll array
 *
 * */
