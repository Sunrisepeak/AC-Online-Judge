/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-22 17:41:07 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-22 17:41:34
 */


// run time: 6ms
#include <iostream>
#include <string>
#include <stack>

using namespace std;
int M, N, K, pushNum;

bool popOK(stack<int> &s, int num) {
    while (s.size() <= M) {
        if (!s.empty() && s.top() == num) {
            //cout << "debug: " << s.top() << endl;
            s.pop();
            return true;
        } else {
            if (pushNum > N) break;
            s.push(pushNum++);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int popNum;
        stack<int> s;
        pushNum = 1;
        int j = 0;
        for (; j < N; j++) {
            cin >> popNum;
            if (!popOK(s, popNum)) {
                break;
            }
        }

        if (j == N) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        // clearing remain numbers for the line
        string trash;
        getline(cin, trash);
    }
    return 0;
}