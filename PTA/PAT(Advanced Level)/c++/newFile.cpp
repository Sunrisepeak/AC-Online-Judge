#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree(1010), nums;
int N, count = 0;

void createCBT(int root) {			// root = 1
	if (root <= N && ::count < N) {
		createCBT(2 * root);		// left tree
		tree[root] = nums[::count++];
		createCBT(2 * root + 1);	// right tree
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	createCBT(1);
	cout << tree[1];
	for (int i = 2; i <= N; i++) {
		cout << " " << tree[i];
	}
	return 0;
}
// array Tree
