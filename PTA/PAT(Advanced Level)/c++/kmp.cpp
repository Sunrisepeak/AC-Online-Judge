#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> nextArr;
/**
 * example:
 *      12312       --> suffix
 *         12312    --> prefix
 *          ^
 *          |
 *nextArr[4] = 1;
*/
void getNextArr(const string &s) {
    int j = -1;
    nextArr[0] = -1;
    for (int i = 1; i < s.length(); i++) {
        while (j != -1 && s[i] != s[j + 1]) {
            j = nextArr[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        nextArr[i] = j;
    }
}

/**
 * text --> suffix-str
 *      pattern --> prefix-str
 *  merge:
 *      pattern-text
 *      j       i
*/
int KMP(const string &text, const string &pattern) {
    getNextArr(pattern);
    int j = -1, cnt = 0;
    for (int i = 0; i < text.length(); i++) {
        while (j != -1 && text[i] != pattern[j + 1]) {
            j = nextArr[j];
        }                
        if (text[i] == pattern[j + 1]) {
            j++;
        }
        if (j == pattern.length() - 1) {
            cnt++;
            j = nextArr[j];
        }
    }
    return cnt;
}

int main() {
    string t, p;
    cin >> t >> p;
    nextArr.resize(p.length());
    cout << KMP(t, p) << endl;
    return 0;
}