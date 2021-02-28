class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        // 2 * 2 > 1 * 3
        uint64_t timesOf3 = n / 3 - (n % 3 == 1);
        uint64_t timesOf2 = (n - timesOf3 * 3) / 2;
        return myPow(3, timesOf3) * myPow(2, timesOf2) % 1000000007;
    }
private:
    uint64_t myPow(int base, int times) {
        uint64_t ans = 1;
        for (int i = 1; i <= times; i++) {
            ans = ans * base % 1000000007;
        }
        return ans;
    }
};
