#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    vector<string> num_seg;
    int N;
    string input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        num_seg.push_back(input);
    }
    sort(num_seg.begin(), num_seg.end(), cmp);
    string ans = "";
    for (int i = 0; i < num_seg.size(); i++) {
        ans += num_seg[i];
    }
    int nonzero = 0;
    while (nonzero < ans.length() - 1 && ans[nonzero] == '0') {
        nonzero++;
    }
    cout << ans.substr(nonzero); 
    return 0;
}
