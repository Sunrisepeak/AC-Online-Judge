#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int n13, n2;
    n13 = str.size() / 2;
    n2 = str.size() - n13 * 2 + 2;
    while (n2 < n13) {
	n2 += 2;
	n13--;	// equal n1-- and  n3--
    }
    // print vertical line
    for (int i = 0; i < n13 - 1; i++) {
	cout << str[i] << string(n2 - 2, ' ') << str[str.size() - i - 1] << endl;
    }
    // print bottom line
    for (int i = n13 - 1; i < n13 - 1 + n2; i++) {
	cout << str[i];
    }
    cout << endl;
    return 0;
}
