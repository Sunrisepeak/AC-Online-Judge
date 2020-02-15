#include <iostream>
#include <string>

using namespace std;

void bigDiv(string a, int b, string &q, int &r) {
    int current = 0;
    for (int i = 0; i < a.length(); i++) {
        current = current * 10 + (a[i] - '0'); 
        if (current < b) {
            q += "0";
            continue;
        }
        q += to_string(current / b);
        current %= b;
    }
    r = current;
}

int main() {
    string a, q;
    int b, r;
    cin >> a >> b;
    bigDiv(a, b, q, r);
    if ( q == "0") 
        cout << q << " " << r;
    else {
        int begin = 0;
        while (q[begin] == '0') {
            begin++;
        }
        cout << q.substr(begin) << " " << r;
    }
    return 0;
}
