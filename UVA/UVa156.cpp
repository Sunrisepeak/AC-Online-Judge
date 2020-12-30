#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

map<string, int> cnt;
set<string> words;

string tolowerAndSort(string w) {
    for (auto &c : w)
	c = tolower(c);
    sort(w.begin(), w.end());
    return w;
}


int main() {
    string word;
    while (cin >> word && word[0] != '#') {
	auto tempStr = tolowerAndSort(word);
	words.insert(word);
	if (cnt.find(tempStr) != cnt.end()) cnt[tempStr]++;
	else cnt[tempStr] = 1;
    }
    for (auto word : words) {
	if (cnt[tolowerAndSort(word)] == 1) {
	    cout << word << endl;
	}
    }
    return 0;
}
