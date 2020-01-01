#include <iostream>
#include <string>
using namespace std;
int alpha_hash[150] = { 0 };
int main() {
    string text;
    getline(cin, text);
    for(auto c : text) {
        if(isalpha(c)) {
            if(isupper(c)) {
                alpha_hash[tolower(c)]++;
            } else {
                alpha_hash[c]++;
            }
        }
    }
    int ans = 97;
    for(int i = 97; i < 124; i++) {
        if(alpha_hash[i] > alpha_hash[ans]) {
            ans = i;
        }
    }
    cout << static_cast<char>(ans) << " " <<alpha_hash[ans];
    return 0;
}
