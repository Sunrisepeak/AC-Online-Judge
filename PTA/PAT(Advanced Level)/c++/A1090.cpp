/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-02 15:35:04 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-02 16:18:32
 */

#include <iostream>
#include <vector>

using namespace std;

struct STreeNode {
    //double price;
    vector<int> child;
};

STreeNode tree[100000];
int N, number { 0 };
double P, R, maxP { 0.0 };

void countPrice(int root, double price) {
    double newPrice = price * (1 + R);
    int i = 0;
    for (; i < tree[root].child.size(); i++) {  // all of child
        countPrice(tree[root].child[i], newPrice);
    }
    if (i == 0) {   // leaf Node
        if (price == maxP) {
            number++;
        }
        if (price > maxP) {
            maxP = price;
            number = 1;
        }
    }
}

int main() {
    cin >> N >> P >> R;
    int root = -1;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp < 0) {
            root = i;
        } else {
            tree[temp].child.push_back(i);
        }
    }
    R /= 100;
    countPrice(root, P);
    printf("%.2f %d", maxP, number);
    return 0;
}