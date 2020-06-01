#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
const int maxn = 50;

struct Node {
    int data;
    Node *lchild, *rchild;
};

int pre[maxn], in[maxn];
int n;

Node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return nullptr;
    }
    Node* root = new Node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

int num = 0;
void postOrder(Node *root) {
    if (root != nullptr) {

        postOrder(root->lchild);
        postOrder(root->rchild);
        cout << root->data;
        num++;
        if (num < n) {
            cout << " ";
        }
    }
}

int main() {
    cin >> n;
    string str;
    stack<int> st;
    int x, preIndex = 0, inIndex = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> str;
        if (str == "Push") {
            cin >> x;
            pre[preIndex++] = x;
            st.push(x);
        } else {
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    Node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}