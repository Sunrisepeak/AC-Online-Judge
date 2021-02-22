class Solution {
public:
    string removeKdigits(string num, int k) {
        int stackTop = 0, j = 0;
        for (; j < num.size(); j++) {
            while (k && stackTop > 0 && num[stackTop - 1] > num[j]) {
                stackTop--; k--;
            }
            num[stackTop++] = num[j];
        }
        stackTop -= k;
        int preZeroLen { 0 };
        while (preZeroLen < stackTop && num[preZeroLen] == '0') preZeroLen++;
        return preZeroLen == stackTop ? "0" : num.substr(preZeroLen, stackTop - preZeroLen);
    }
};

/**
 *
 *  1.stack
 *  2.greedy
 *  3.double pointer
 *
 * */
