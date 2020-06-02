/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-02 17:07:37 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-02 17:29:40
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100000];
int N, number { 0 };
double P, R, minP { 1u << 31u };

void countPrice(int root, double p) {
    double newP = p * (1 + R);
    int i = 0;
    for (; i < tree[root].size(); i++) {
        countPrice(tree[root][i], newP);
    }
    if (i == 0) {   // is leaf Node
        if (p == minP) {
            number++;
        }
        if (p < minP) {
            minP = p;
            number = 1;
        }
    }
}

int main() {
    cin >> N >> P >> R;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int temp;
            cin >> temp;
            tree[i].push_back(temp);
        }
    }
    R /= 100;
    countPrice(0, P);
    printf("%.4f %d", minP, number);
    return 0;
}