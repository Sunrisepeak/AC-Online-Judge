/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-03 16:37:02 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-03 18:35:07
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define mian main   // play to play

using namespace std;

struct STreeNode {
    int weight;
    vector<int> child;
};

STreeNode tree[110];
int N, M, S;
vector<int> path;
vector<vector<int> > paths;

/**
 *  Note: 
 *      In C++, your "compare" predicate must be a strict weak ordering.
 *      In particular, "compare(X,X)" must return "false" for any X.
 * 
 *  Ref: https://stackoverflow.com/questions/1541817/sort-function-c-segmentation-fault
 */

bool cmp(const vector<int> &A, const vector<int> &B) {
    int minSize = min(A.size(), B.size());
    for (int i = 0; i < minSize; i++) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    if (A.size() <= B.size()) {     // here, cann't is <
        return false;
    }
    return true;    // A.size() >= B.size()
}

void wPath(int root, int pathSum) {
    path.push_back(tree[root].weight);  // push

    pathSum += tree[root].weight;
    int i = 0;
    for (; i < tree[root].child.size(); i++) {
        wPath(tree[root].child[i], pathSum);
    }
    if (i == 0 && pathSum == S) {
        paths.push_back(path);
    }
    
    path.pop_back();                    // pop
}

int mian() {
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++) {
        cin >> tree[i].weight;
    }
    for (int i = 0; i < M; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int temp;
            cin >> temp;
            tree[id].child.push_back(temp);
        }
    }
    wPath(0, 0);
    sort(paths.begin(), paths.end(), cmp);
    for (int i = 0; i < paths.size(); i++) {
        if (paths[i].size() != 0)
            cout << paths[i][0];
        for (int j = 1; j < paths[i].size(); j++) {
            cout << " " << paths[i][j];
        }
        cout << endl;
    }
    return 0;
}