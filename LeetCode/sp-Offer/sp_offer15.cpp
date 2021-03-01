class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
        /*
        int cnt = 0;
        while (n) {
            cnt++;
            // Example: 1100 - 1 = 1011 => 1100 & 1011 = 1000
            n &= (n - 1);
        }
        return cnt;
        */
    }
};
