/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-26 15:43:22 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-26 16:31:21
 */

// runtime: 116ms
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

struct SLNode {
    int key;
    int ad;    // self_ad / next_ad
}Mem[100010];

int main() {
    int AD, N;
    scanf("%d%d", &AD, &N);
    for (int i = 0; i < N; i++) {
        int ad;
        scanf("%d", &ad);
        scanf("%d%d", &Mem[ad].key, &Mem[ad].ad);
    }
    map<int, bool> hashTable;
    vector<SLNode> L1, L2;
    int p = AD;
    while (p != -1) {
        int next = Mem[p].ad;
        Mem[p].ad = p;          // self_ad
        if (hashTable.find(abs(Mem[p].key)) == hashTable.end()) {
            hashTable[abs(Mem[p].key)] = true;
            L1.push_back(Mem[p]);
        } else {
            L2.push_back(Mem[p]);
        }
        p = next;
    }
    
    for (int i = 0; i < L1.size() - 1; i++) {
        printf("%05d %d %05d\n", L1[i].ad, L1[i].key, L1[i + 1].ad);
    }
    printf("%05d %d -1\n", L1[L1.size() - 1].ad, L1[L1.size() - 1].key);

    for (int i = 0; i < static_cast<int>(L2.size() - 1); i++) {
        printf("%05d %d %05d\n", L2[i].ad, L2[i].key, L2[i + 1].ad);
    }
    if (L2.size() > 0)
        printf("%05d %d -1", L2[L2.size() - 1].ad, L2[L2.size() - 1].key);
    return 0;
}

/*
 *  Note: i < L2.size() - 1
 *          int < uint - int ==> uint < uint - uint
 *          when L2.size() = 0,
 *          generating error because '-1' is regarded of uint-type
 */