/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-19 17:50:56 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-19 17:52:42
 */

// run time: 169ms
#include <iostream>
#include <cctype>
#include <string>
#include <map>

using namespace std;

/*
 *  Overwirte: tolower(char)
 *  Notice: cann't only deal with being of word
 */
void tolower(string &str) {
    for (u_int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            // notice: tolower(a), a is not reference
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    map<string, int> words;
    string text, ans;
    getline(cin, text);
    text.append("\n");      // getline lose '\n'
    int begin, max = 0;     // forget init for max [spend 20min]
    bool lockOpen = true;
    for (u_int i = 0; i < text.length(); i++) {
        if (lockOpen && isalnum(text[i])) {
            begin = i;
            lockOpen = false;
        }
        if (!lockOpen && !isalnum(text[i])) {
            lockOpen = true;
            string word = text.substr(begin, i - begin);
            
            tolower(word);

            if (words.find(word) != words.end()) {
                words[word]++;
            } else {
                words[word] = 1;
            }
            if (words[word] > max) {
                ans = word;
                max = words[word];
            }
        }
    }
    cout << ans << " " << max << endl;
    return 0;
}