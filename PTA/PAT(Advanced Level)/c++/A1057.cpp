#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

const int MAX = 100001;
const int MAXB = sqrt(MAX) + 1;
vector<int> table(MAXB * MAXB + 1, 0), block(MAXB, 0);
stack<int> st;

void Pop() {
    int temp = st.top();
    st.pop();
    cout << temp << endl;
    block[temp / MAXB]--;
    table[temp]--; 
}

void PeekMedian(int K) {
    int bIndex = 0, sum = 0;
    while (sum + block[bIndex] < K) {
        sum += block[bIndex++];
    }
    int num = bIndex * MAXB;
    while (sum + table[num] < K) {
        sum += table[num++];          
    }
    cout << num << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    string tInput;
    cin >> N;
    getline(cin, tInput);  // del '\n'
    for (int i = 0; i < N; i++) {
        getline(cin, tInput);
        if (tInput.substr(0, 2) == "Pu") {
            int begin = tInput.length() - 1;
            while (tInput[begin] != ' ') begin--;
            int num = stoi(tInput.substr(begin + 1));
            st.push(num);
            table[num]++;
            block[num / MAXB]++;
        } else if (st.size() != 0) {
            if (tInput.substr(0, 2) == "Pe") {
                PeekMedian((st.size() + 1) / 2);
            } else {
                Pop();
            }
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}