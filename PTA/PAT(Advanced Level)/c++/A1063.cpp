#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<set<int> > vset(N + 1);
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            vset[i].insert(temp);
        }
    }
    int query;
    cin >> query;
    for (int i = 0; i < query; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        int same = 0;
        for (auto it = vset[n2].begin(); it != vset[n2].end(); it++) {
            if (vset[n1].find(*it) != vset[n1].end()) {
                same++;
            }
        }
        int different = vset[n1].size() + vset[n2].size() - same;
        printf("%.1lf%\n", same * 100 / static_cast<double>(different));

    }
    return 0;
}
