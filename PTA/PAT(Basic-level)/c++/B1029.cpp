#include <iostream>

using namespace std;

int main() {
    bool hash_table[130] = { false };
    string s;
    cin >> s;
    char c;
    while(cin >> c) {
        hash_table[toupper(c)] = true;
    }
    for(auto ch : s) {
        ch = toupper(ch);
        if(!hash_table[ch]) {
            cout << ch;
            hash_table[ch] = true;
        }
    }
    return 0;
}
