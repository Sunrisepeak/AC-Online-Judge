/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-02 17:33:19 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-02 17:55:18
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[110];
bool idHash[110] { false };
int N, M, levNodeNum[110] { 0 }, maxLevel = 0;

void DFS(int root, int level) {
    int i = 0;
    for (; i < tree[root].size(); i++) {
        DFS(tree[root][i], level + 1);
    }
    if (i == 0) {   // is leaf Node
        levNodeNum[level]++;
        if (level > maxLevel) {
            maxLevel = level;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int ID, K;
        cin >> ID >> K;
        for (int j = 0; j < K; j++) {
            int temp;
            cin >> temp;
            tree[ID].push_back(temp);
            idHash[temp] = true;
        }
    }
    int root = 1;
    for (; root < N; root++) {
        if (idHash[root] == false) {
            break;
        }
    }
    DFS(root, 0);
    cout << levNodeNum[0];
    for (int i = 1; i <= maxLevel; i++) {
        cout << " " << levNodeNum[i];
    }
    return 0;
}