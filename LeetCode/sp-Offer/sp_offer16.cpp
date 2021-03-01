class Solution {
public:
    double myPow(double x, int n) {
        long long times = n;
        if (times < 0) {
            x = 1 / x;
            times = -times;
        }
        double ans = 1, timesOfX = x;
        while (times) {
            if (times & 1) ans *= timesOfX;
            timesOfX *= timesOfX;
            times >>= 1;
        }
        return ans;
    }
};
