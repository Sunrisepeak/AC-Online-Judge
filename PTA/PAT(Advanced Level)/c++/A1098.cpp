#include <iostream>
#include <vector>

using namespace std;

vector<int> maxHeap, nums;

bool isMaxHeap(int low, int high) {
	for (int i = high; i > low; i--) {
		int father = i / 2;
		if (father >= low) {
			if (maxHeap[father - 1] < maxHeap[i - 1]) {	// shift 1 (toward left)
				return false;
			}
		}
	}
	return true;	
}

void downAdjust(int low, int high) {
	int i = low, j = 2 * i;
	while (j <= high) {
		if (j + 1 <= high && maxHeap[j + 1 - 1] > maxHeap[j - 1]) {
			j = j + 1;
		}
		if (maxHeap[j - 1] > maxHeap[i - 1]) {
			swap(maxHeap[j - 1], maxHeap[i - 1]);
			i = j;
			j = i * 2;
		} else {	// root > child
			break;
		}
	}
}

int subHeapSize;
bool isHeapSort() {
	int maxNum = -1;
	for (int i = maxHeap.size() - 1; i >= 0; i--) {	// get maxNum
		if (maxHeap[i] > maxNum) {
			maxNum = maxHeap[i];
		}
	}
	if (maxHeap[maxHeap.size() - 1] != maxNum) return false;
	int compareNum = maxNum, k;
	for (k = maxHeap.size() - 1; k >= 0; k--) {		// find last element of heap
		if (maxHeap[k] > compareNum) {
			break;
		}
		compareNum = maxHeap[k];
	}
	subHeapSize = k + 1;
	// shift 1 [0 -> 1 : heap begin-pos]
	return isMaxHeap(1, subHeapSize);
}

int main() {
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		nums.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		maxHeap.push_back(temp);
	}
	if (isHeapSort()) {
		cout << "Heap Sort" << endl;
		swap(maxHeap[0], maxHeap[subHeapSize]);
		downAdjust(1, subHeapSize);				// shift 1 : [subHeapSize = last-element + 1]
	} else {
		cout << "Insertion Sort" << endl;
		int min = maxHeap[0], k;
		for (k = 0; k < maxHeap.size(); k++) {	// find element of need to insert
			if (maxHeap[k] < min) {
				break;
			}
			min = maxHeap[k];
		}
		
		// insert sort [once]
		int save = maxHeap[k], j = k - 1;
		while(0 <= j && maxHeap[j] > save) {
			maxHeap[j + 1] = maxHeap[j];
			j--;
		}
		maxHeap[j + 1] = save;
	}
	cout << maxHeap[0];
	for (int i = 1; i < maxHeap.size(); i++) {
		cout << " " << maxHeap[i];
	}
	return 0;
} 
