#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
	int data;
	int lchild, rchild;
};

vector<TreeNode> tree(110);
vector<int> nums;
bool indexHash[110] { false };
int N, count { 0 };

void fill(int root) {
	if (root != -1) {
		fill(tree[root].lchild);
		tree[root].data = nums[::count++];
		fill(tree[root].rchild);
	}
}

bool firstOut { true };
void levelOrder(int root) {
	queue<int> tQ;
	tQ.push(root);
	while(!tQ.empty()) {
		int index = tQ.front();
		tQ.pop();
		if (firstOut) {
			cout << tree[index].data;
			firstOut = false;
		} else {
			cout << " " << tree[index].data;
		}

		if (tree[index].lchild != -1) 
			tQ.push(tree[index].lchild);
		if (tree[index].rchild != -1) 
			tQ.push(tree[index].rchild);
	}
	
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tree[i].lchild >> tree[i].rchild;
		if (tree[i].lchild != -1)
			indexHash[tree[i].lchild] = true;
		if (tree[i].rchild != -1)
			indexHash[tree[i].rchild] = true;
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	int root = -1;
	for (int i = 0; i < N; i++) {
		if (!indexHash[i]) {
			root = i;
			break;
		}
	}
	sort(nums.begin(), nums.end());
	fill(root);
	levelOrder(root);
	return 0;
}
