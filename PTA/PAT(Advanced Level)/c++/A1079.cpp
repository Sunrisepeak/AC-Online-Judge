/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-01 16:15:59 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-01 17:34:08
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct STreeNode {
    double price;
    vector<int> child;
    int pNum { -1 };    // product numbers
};

STreeNode chain[100000];

void countPrice(int root, double price, double R) {
    chain[root].price = price;
    double newPrice = price * (1 + R);
    // all of child
    for (int i = 0; i < chain[root].child.size(); i++) {    
        countPrice(chain[root].child[i], newPrice, R);
    }
}

int main() {
    int N;
    double P, R;
    cin >> N >> P >> R;
    for (int i = 0; i < N; i++) {
        int K, temp;
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> temp;
            chain[i].child.push_back(temp);
        }
        if (K == 0) {
            cin >> chain[i].pNum;
        }
    }
    countPrice(0, P, R / 100);
    double sum { 0 };
    for (int i = 0; i < N; i++) {
        if (chain[i].pNum > 0) {
            sum += chain[i].pNum * chain[i].price;
        }
    }
    printf("%.1f", sum);
    return 0;
}