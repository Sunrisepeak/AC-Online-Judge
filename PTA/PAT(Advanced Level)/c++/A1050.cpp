#include <iostream>
#include <string>
using namespace std;
bool alpha_hash[150] = { false };
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for(auto c : s2) {
        alpha_hash[c] = true;
    }

    for(auto c : s1) {
        if(alpha_hash[c] == false) {
            cout << c;
        }
    }
    return 0;
}
