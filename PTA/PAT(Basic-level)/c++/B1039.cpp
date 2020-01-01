#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int color_hash[256]{ 0 };
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(auto c : s1) {
        color_hash[c]++;
    }
    int count_color = 0;    //count for match success
    bool isYes = true;
    for(auto c : s2) {
        if(color_hash[c] > 0) {
            count_color++;
            color_hash[c]--;
        } else {
            isYes = false;
        }
    }
    if(isYes) {
        cout << "Yes " << s1.length() - s2.length();
    } else {
        cout << "No " << s2.length() - count_color;
    }
    return 0;
}
