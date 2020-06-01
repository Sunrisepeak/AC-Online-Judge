/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-29 10:30:24 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-29 11:33:00
 */


// runtiem: 4ms
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> postOrder, inOrder;

struct TreeNode {
    int data;
    TreeNode *left, *right;
};

TreeNode * creatTree(int &pIndex, int iIndexL, int iIndexR) {
    TreeNode *node { nullptr };
    if (pIndex >= 0 && pIndex < postOrder.size() && iIndexL <= iIndexR) {
        node = new TreeNode();
        node->data = postOrder[pIndex];
        int splitPoint = -1;
        for (int i = iIndexL; i <= iIndexR; i++) {
            if (inOrder[i] == postOrder[pIndex]) {
                splitPoint = i;
                break;
            }
        }
        pIndex--;
        node->right = creatTree(pIndex, splitPoint + 1, iIndexR);
        node->left = creatTree(pIndex, iIndexL, splitPoint - 1);
        //note: left after right
    }
    return node;
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        postOrder.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        inOrder.push_back(temp);
    }
    TreeNode *root { nullptr };
    int size = postOrder.size() - 1;
    root = creatTree(size, 0, inOrder.size() - 1);
    queue<TreeNode*> treeQ;
    treeQ.push(root);
    int count = 0;
    while (!treeQ.empty()) {
        TreeNode *temp = treeQ.front();
        treeQ.pop();
        if (temp != nullptr) {
            count++;
            treeQ.push(temp->left);
            treeQ.push(temp->right);
            cout << temp->data;
            cout << (count == N ? "" : " ");
        }
    }
    return 0;
}