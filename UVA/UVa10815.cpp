#include <iostream>
#include <cctype>
#include <string>
#include <set>
#include <sstream>

using namespace std;

set<string> dict;

int main() {
    string text = "";
    char c;
    while ((c = getchar()) != EOF) {
	if (!isalpha(c)) c = ' ';
	else c = tolower(c);
	text += c;
    }
    stringstream newText(text);
    string words;
    while (newText >> words) {
	dict.insert(words);
    }
    for (auto it : dict) {
	cout << it << endl;
    }
    return 0;
}
