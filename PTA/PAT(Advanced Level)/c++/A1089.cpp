#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> target, ans;

bool insert_sort(vector<int> sequ) {
    bool flag = false;
    for (int i = 1; i < sequ.size(); i++) {
        if (i != 1 && sequ == target) {
            flag = true;
        }
        int p = i, temp = sequ[i];
        while (p > 0 && sequ[p - 1] > temp) {
            sequ[p] = sequ[p - 1]; 
            p--;
        }
        sequ[p] = temp;
        if (flag) {
            cout << "Insertion Sort" << endl;
            ans = sequ;
            return true;
        }
    }
    return false;
}

void merge(vector<int> &sequ, int l1, int r1, int l2, int r2) {
    vector<int> temp;
    int begin = l1;
    while (l1 <= r1 && l2 <= r2) {
        if (sequ[l1] <= sequ[l2]) {
            temp.push_back(sequ[l1++]);
        } else {
            temp.push_back(sequ[l2++]);
        }
    }
    while (l1 <= r1) {
        temp.push_back(sequ[l1++]);
    }
    while (l2 <= r2) {
        temp.push_back(sequ[l2++]);
    }
    for (int i = 0; i < temp.size(); i++, begin++) {
        sequ[begin] = temp[i];
    }
}


/*
 void merge_sort(vector<int>& sequ, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        merge_sort(sequ, begin, mid);
        merge_sort(sequ, mid + 1, end);
        merge(sequ, begin, mid, mid + 1, end);
        if (sequ == target) {
            mlock = true;
        }
    }
}
*/

void merge_sort(vector<int> sequ) {
    int width = 1;
    bool flag = false;
    while (width <= sequ.size()) {
        if (width != 1 && sequ == target) {
            flag = true;
        }
        for (int i = 0; i < sequ.size(); i += 2 * width) {
            int l = i, mid = l + width, r = l + 2 * width - 1;
            if (r > sequ.size() - 1) {
                r = sequ.size() - 1;
            }
            if (mid > sequ.size() - 1) {
                continue; 
            }
            merge(sequ, i, mid - 1, mid, r); 
            //sort(sequ.begin() + i, sequ.begin() + min(i + width, (int)sequ.size()));
        }
        if (flag) {
            cout << "Merge Sort" << endl;
            ans = sequ;
            return;
        }
        width *= 2;
    }
}

int main() {
    int N, input;
    vector<int> sequ;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        sequ.push_back(input);
    }
    for (int i = 0; i < N; i++) {
        cin >> input;
        target.push_back(input);
    }
    if (!insert_sort(sequ)) {
        merge_sort(sequ);
    }
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    return 0;
}
