#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int splitLineLen = 60;
vector<string> fileList;

void formatPrint(const string &s, const decltype(s.length()) fLen) {
    cout << s;
    for (auto i =  s.length(); i <= fLen; i++) {
	cout << " ";
    }
}

int main() {
    int fileNum;
    while (cin >> fileNum) {
	string fName;
	decltype(fName.length()) maxLen = 0;
	while (fileNum--) {
	    cin >> fName;
	    maxLen = max(maxLen, fName.length());
	    fileList.push_back(fName);
	}
	for (int i = 0; i < splitLineLen; i++) 
	    cout << "-";
	cout << endl;
	auto col = (splitLineLen - maxLen) / (maxLen + 2) + 1;
	auto row = fileList.size() / col + (fileList.size() % col != 0);
	sort(fileList.begin(), fileList.end());
	for (decltype(row) r = 0; r < row; r++) {	// print
	    for (decltype(col) c = 0; c < col; c++) {
		auto index = c * row + r;
		if (index < fileList.size()) {
		    formatPrint(fileList[index], maxLen); 
		    cout << (c != col - 1 ? "  " : "");
		}
	    }
	    cout << endl;
	}
	fileList.clear();
    }
    return 0;
}
