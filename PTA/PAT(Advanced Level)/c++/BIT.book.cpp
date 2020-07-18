#include <iostream>
#include <vector>
#define lowbit(x) (-x&x)

using namespace std;

const int MAXN = 1000;
vector<int> c(MAXN, 0);

void update(int num, int incre) {
    for (int i = num; i < MAXN; i += lowbit(i)) {
        c[i] += incre;
    }
}

int getSum(int num) {
    int sum { 0 };
    for (int i = num; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        update(x, 1);
        // equal query num of its left-side less than x
        cout << "[numOfLeftBettMin]: " << getSum(x - 1) << endl;    
    }
    return 0;
}

/**
 * input:  8 1 4 1 2 2 3 5 4
 * output: 
 * 
 * note[left-side]:
 *      less than: getSum(x - 1)
 *      lessAndEqual: getSum(x) - 1(self)
 *      great than: getSum(N) - getSum(x)
 * 
*/