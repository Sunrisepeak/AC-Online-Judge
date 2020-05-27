/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-26 14:51:20 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-26 15:42:07
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct SLNode{
    int key;
    int next_ad;   // ad/next
}Mem[100010];


bool cmp(const SLNode &A, const SLNode &B) {
    return A.key < B.key;
}

int main() {
    int N, Head;
    scanf("%d%d", &N, &Head);
    if (Head == -1) {
        printf("0 -1");
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int ad;
        scanf("%d", &ad);
        scanf("%d%d", &Mem[ad].key, &Mem[ad].next_ad);
    }
    vector<SLNode> List;
    int p = Head, num { 0 };
    while (p != -1) {
        int next = Mem[p].next_ad;  // save next ad
        Mem[p].next_ad = p;         // ad = self_ad
        List.push_back(Mem[p]);
        p = next;                   // next
    }
    sort(List.begin(), List.end(), cmp);
    printf("%d %05d\n", List.size(), List[0].next_ad);
    for (int i = 0; i < List.size() - 1; i++) {
        printf("%05d %d %05d\n", List[i].next_ad, List[i].key, List[i + 1].next_ad);
    }
    printf("%05d %d -1", List[List.size() - 1].next_ad, List[List.size() - 1].key);
    return 0;
}