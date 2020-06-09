#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int data;
	TreeNode *lChild, *rChild;
};

TreeNode * RR(TreeNode *root) {
	auto newRoot = root->lChild;
	root->lChild = newRoot->lChild;
	newRoot->rChild = root;
	return newRoot;
}
 
TreeNode * LR(TreeNode *root) {
	auto newRoot = root->rChild;
	root->rChild = newRoot->lChild;		// cover original child root
	newRoot->lChild = root;
	return newRoot;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		
	}
	return 0;
}
