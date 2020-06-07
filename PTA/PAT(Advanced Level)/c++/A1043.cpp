#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int data;
	TreeNode *lchild, *rchild;
};

int preOrder[1010] { 0 }, N, number { 0 };
vector<int> inOrder;
bool isTree, findOrder { true };
/**
 *	@return : index of value in inOrder [local]
 */
int find(int L, int R, int value, bool beginToEnd) {
	int k;
	if (beginToEnd) {
		for (k = L; k <= R; k++) {
			if (value == inOrder[k]) {
				break;
			}
		}
	} else {
		for (k = R; k >= L; k--) {
			if (value == inOrder[k]) {
				break;
			}
		}
	}
	return k;
} 


TreeNode * creTreeByPreIn(int preL, int preR, int inL, int inR) {
	TreeNode *root { nullptr };
	if (isTree && preL <= preR) {
		root = new TreeNode();
		root->data = preOrder[preL];
		int k = find(inL, inR, preOrder[preL], findOrder);
		if (k > inR || k < 0) {
			isTree = false;
		}
		root->lchild = creTreeByPreIn(preL + 1, preL + (k - inL), inL, k - 1);
		root->rchild = creTreeByPreIn(preR - (inR - k) + 1, preR, k + 1, inR);
	}
	return root;
}

void postOrder(TreeNode *root) {
	if (root != nullptr) {
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout << root->data;
		number++;
		cout << (number == N ? "" : " ");
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> preOrder[i];
		inOrder.push_back(preOrder[i]);
	}
	sort(inOrder.begin(), inOrder.end());
	isTree = true;
	auto root = creTreeByPreIn(0, N - 1, 0, N - 1);
	if (!isTree) {
		reverse(inOrder.begin(), inOrder.end());
		isTree = true;
		findOrder = false;
		root = creTreeByPreIn(0, N - 1, 0, N - 1);
		
	}
	if (isTree) {
		cout << "YES" << endl;
		postOrder(root);
	} else {
		cout << "NO";
	}
	return 0;
}
/**
 *	Note: it is finding root-element from left to right when LTree{} <(>) Root <=(>=) RTree{}
 *		  it is to the contrary when LTree{} <=(>=) Root <(>) RTree{}
 *
 */
