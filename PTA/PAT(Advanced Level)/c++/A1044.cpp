#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int l, r;
};

vector<Pair> ans;
vector<int> diam;
int mixsum = (1 << 31) - 1;
void push(int l, int r, int s) {
    if (s < mixsum) {
        ans.clear();
        mixsum = s;
    }
    if (s == mixsum) {
        Pair temp;
        temp.l = l + 1;
        temp.r = r + 1;
        ans.push_back(temp);
    }
}

int main() {
    int N, sum, input;
    cin >> N >> sum;
    for (int i = 0; i < N; i++) {
        cin >> input;
        diam.push_back(input);
    }
    int l{ 0 }, r{ 0 }, s{ 0 };
    s = diam[0];
    while (l < diam.size() && r < diam.size()) {
        if (s == sum) {
            push(l, r, s);
            s -= diam[l];
            l++;
            r++;
            if (r < diam.size())
                s += diam[r];
        } else if (s < sum) {
            r++;
            if (r < diam.size())
                s += diam[r];
        } else {
            push(l, r, s);
            s -= diam[l];
            l++;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].l << "-" << ans[i].r << endl;
    }
    return 0;
}
