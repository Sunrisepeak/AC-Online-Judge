#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void input(vector<int>& s, int num) {
    int temp;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        s.push_back(temp);
    }
}

int main() {
    vector<int> s1, s2;
    int N;
    cin >> N;
    input(s1, N);
    cin >> N;
    input(s2, N);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int ans = 0;
    int i = 0, j;
    while (i < s1.size() && i < s2.size() &&  s1[i] < 0 && s2[i] < 0) {
        ans += s1[i] * s2[i];
        i++;     
    }
    i = s1.size() - 1;
    j = s2.size() - 1;
    while (i >= 0 && j >= 0 && s1[i] > 0 && s2[j] > 0) {
        ans += s1[i] * s2[j];
        i--;
        j--;
    }
    cout << ans;
    return 0;
}
