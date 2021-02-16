#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string replaceSpace(string s) {
    string::size_type oldSize = s.size();
    auto cnt = count(s.begin(), s.end(), ' ');
    s.append(cnt * 2, '1');
    // can't unsigned number(and auto) (uint >= 0)
    for (int p1 = oldSize - 1, p2 = s.size(); p1 >= 0; p1--) {
        if (s[p1] == ' ') {
            p2 -= 3;
            s.replace(p2, 3, "%20");
        } else {
            s[--p2] = s[p1];
        }
    }
    return s;
}

int main() {
    cout << replaceSpace("this is a test.");
    return 0;
}
