class Solution {
public:
    //f(n) = f(n - 1) + f(n - 2);
    int numWays(int n) {
        int f2 = 1, f1 = 1; // f(0), f(1)
        for (int i = 2; i <= n; i++) {
            int f3 = (f1 + f2) % 1000000007;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};
