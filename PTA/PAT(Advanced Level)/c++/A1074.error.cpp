/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-25 17:59:01 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-25 22:31:31
 */


// case5: wrong answer
#include <iostream>

using namespace std;

struct StaticLList {
    int data;
    int next;
}List[100100];

int reverseLList(int pre, int begin, int k) {
    int rL = begin, newBegin;
    //right list
    for (int i = 0; i < k; i++) {
        if (i + 1 == k) {
            newBegin = rL;
        }
        rL = List[rL].next;
        if (rL == -1) {
            break;
        }
    }
    // reverse
    int p1 = rL, p2 = begin;
    while (p2 != rL) {
        int q = List[p2].next;
        List[p2].next = p1;
        //cout << "p2 -> next " << p2 << " -> " << p1 << endl;
        p1 = p2;
        p2 = q;
    }
    
    if (pre > 0) {
        List[pre].next = newBegin;
    }

    //cout << "first -- " << newBegin << endl;

    return newBegin; // new first-Node
}


int main() {
    int firstAD, N, K;
    scanf("%d%d%d", &firstAD, &N, &K);
    for (int i = 0; i < N; i++) {
        int ad;
        scanf("%d", &ad);
        scanf("%d%d", &List[ad].data, &List[ad].next);
    }
    
    int p = firstAD, num = 0;
    while (p != -1) {
        p = List[p].next;
        num++;
    }

    int pre, newFirstAd = firstAD;
    if (num >= K) {
        newFirstAd = reverseLList(-1, firstAD, K);
        pre = firstAD;
        for (int i = 0; i < num / K - 1; i++) {
            int temp = List[pre].next;
            reverseLList(pre, temp, K);
            pre = temp;
        }
    }
    
    p = newFirstAd;
    while (p != -1) {
        if (List[p].next == -1) {
            printf("%05d %d -1", p, List[p].data);
            break;
        }
        printf("%05d %d %05d\n", p, List[p].data, List[p].next);
        p = List[p].next;
    }
    return 0;
}

