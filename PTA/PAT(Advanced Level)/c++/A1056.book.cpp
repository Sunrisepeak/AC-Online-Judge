#include <iostream>
#include <queue>

using namespace std;

struct Mouse {
    int weight;
    int R;
}mouse[1010];

int main() {
    int np, ng, order;
    cin >> np >> ng;
    for (int i = 0; i < np; i++) {
        cin >> mouse[i].weight;
    }
    queue<int> q;
    for (int i = 0; i < np; i++) {
        cin >> order;
        q.push(order);
    }
    int temp = np, group;
    while (q.size() != 1) {
        if (temp % ng == 0) group = temp / ng;
        else group = temp / ng + 1;
        for (int i = 0; i < group; i++) {
            int k = q.front();
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= temp) break;
                int front = q.front();
                if (mouse[front].weight > mouse[k].weight) {
                    k = front;
                }
                // becouse winer is only one for each group and
                // the same of grade for each around(mouse)
                mouse[front].R = group + 1;
                q.pop();
            }
            q.push(k);      // winer
        }
        temp = group;       // number of winer
    }
    mouse[q.front()].R = 1;
    cout << mouse[0].R;
    for (int i = 1; i < np; i++) {
        cout << " " << mouse[i].R;
    }
    return 0;
}