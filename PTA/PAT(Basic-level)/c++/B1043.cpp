#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string text;
    map<char, int> ans;
    cin >> text;
    string PATest = "PATest";
    int sum = 0;
    for(auto c : text) {
       if(PATest.find(c) != string::npos) {
           ans[c]++;
           sum++;
       } 
    }
    while(sum) {
        for(int i = 0; i < PATest.length(); i++) {
            if(ans[PATest[i]] > 0) {
                cout << PATest[i];
                ans[PATest[i]]--;
                sum--;
            } else {
                PATest.erase(PATest.begin() + i);
                i--;
            }
        } 
    }
    return 0;
}
