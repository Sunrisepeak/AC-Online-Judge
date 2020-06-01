/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-01 15:20:49 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-01 16:00:45
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int lchild, rchild;
};

int N;
TreeNode tree[11];
bool hash[11] = { false };

void levelOrder(int root) {
    queue<int> nodeQ;
    nodeQ.push(root);
    while(!nodeQ.empty()) {
        int nodeIndex = nodeQ.front();
        nodeQ.pop();
        if (!nodeQ.empty() || tree[nodeIndex].lchild != tree[nodeIndex].rchild) {
            cout << nodeIndex << " ";
            if (tree[nodeIndex].lchild != -1)
                nodeQ.push(tree[nodeIndex].lchild);
            if (tree[nodeIndex].rchild != -1)
                nodeQ.push(tree[nodeIndex].rchild);
        } else {    // over
            cout << nodeIndex << endl;
        }
    }
}

int count { 0 };
void inOrder(int root) {
    if (root != -1) {
        inOrder(tree[root].lchild);
        cout << root;
        count++;
        cout << (count == N ? "" : " ");
        inOrder(tree[root].rchild);
    }
}

int main() {
    cin >> N;
    string temp;
    getline(cin, temp);     // delete '\n'
    for (int i = 0; i < N; i++) {
        getline(cin, temp);
        // invert
        if (temp[0] != '-') {
            tree[i].rchild = temp[0] - '0';
            ::hash[temp[0] - '0'] = true;
        } else tree[i].rchild = -1;
        if (temp[2] != '-') {
            tree[i].lchild = temp[2] - '0';
            ::hash[temp[2] - '0'] = true;
        } else tree[i].lchild = -1;
    }
    int root = 0;
    for (; root < N; root++) {
        if (::hash[root] == false) {
            break;
        }
    }
    levelOrder(root);
    inOrder(root);
    return 0;
}