/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-02 16:20:18 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-02 17:03:31
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct STreeNode {
    vector<int> child;
};

int N, M;
STreeNode tree[110];
bool idHash[110] = { false };

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int temp;
            cin >> temp;
            tree[id].child.push_back(temp);
            idHash[temp] = true;
        }
    }
    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (idHash[i] == false) {
            root = i;
            break;
        }
    }
    vector<int> levNodeNum(110);
    queue<int> tQ;
    int level = 0, number = 0, firNodeOfLev = root;
    tQ.push(root);
    while(!tQ.empty()) {
        int node = tQ.front();
        tQ.pop();
        if (node == firNodeOfLev) {
            levNodeNum[level++] = number;
            number = 0;
            firNodeOfLev = -1;  // set Null(-1)
        }
        number++;
        for (int i = 0; i < tree[node].child.size(); i++) {
            if (firNodeOfLev < 0) {
                firNodeOfLev = tree[node].child[i];
            }
            tQ.push(tree[node].child[i]);
        }
    }
    levNodeNum[level] = number; // last level
    int maxLevel = -1, num = 0;
    for (int i = 1; i <= level; i++) {
        if (levNodeNum[i] > num) {
            num = levNodeNum[i];
            maxLevel = i;
        }
    }
    cout << num << " " << maxLevel;
    return 0;
}