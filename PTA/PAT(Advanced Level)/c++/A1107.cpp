#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Set {
	int size;
	int father;
	set<int> hobbies;
};

vector<Set> ufs(1010);

void init(int n) {
	for (int i = 0; i <= n; i++) {
		ufs[i].father = i;
		ufs[i].size = 1;
	}
}

int findFather(int v) {
	if (ufs[v].father == v) return v;	// careless: 1h because using is '=' rather than '=='
	return ufs[v].father = findFather(ufs[v].father);	//path constract
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		ufs[faA].father = faB;
		ufs[faB].size += ufs[faA].size;
	}
}

bool sameHobbies(int a, int b) {			// NlogN
	if (ufs[a].hobbies.size() > ufs[b].hobbies.size()) {
		swap(a, b);
	}
	auto it = ufs[a].hobbies.begin();
	for (; it != ufs[a].hobbies.end(); it++) {
		if (ufs[b].hobbies.find(*it) != ufs[b].hobbies.end()) {
			return true;
		}
	}
	return false;
}

bool cmp(int A, int B) {
	return ufs[A].size > ufs[B].size;
}

int main() {
	int N;
	cin >> N;
	init(N);
	for (int i = 0; i < N; i++) {
		string K;
		cin >> K;
		for (int j = 0; j < K[0] - '0'; j++) {
			int temp;
			cin >> temp;
			ufs[i].hobbies.insert(temp);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sameHobbies(i, j)) {
				Union(i, j);
			}
		}
	}
	vector<int> sets;
	for (int i = 0; i < N; i++) {
		if (ufs[i].father == i) {
			sets.push_back(i);
		}
	}
	sort(sets.begin(), sets.end(), cmp);
	cout << sets.size() << endl << ufs[sets[0]].size;
	for (int i = 1; i < sets.size(); i++) {
		cout << " " << ufs[sets[i]].size;
	}
	return 0;
}
