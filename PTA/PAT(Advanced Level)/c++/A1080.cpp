#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Student {
    int id;
    int GE, GI;
    vector<int> choice;
    int total;
}stu[40010];

struct School {
    int limit;
    vector<int> stu_id;
}sch[110];

bool cmp(Student A, Student B) {
    if(A.total !=  B.total) return A.total > B.total;
    else return A.GE > B.GE;
}

int main() {
    int N, M, K;
    vector<int> sch_people;
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> sch[i].limit;

    }
    for(int i = 0; i < N; i++) {
        cin >> stu[i].GE >> stu[i].GI;
        stu[i].id = i;
        for(int k = 0; k < K; k++) {
            int x;
            cin >> x;
            stu[i].choice.push_back(x);
        }
        stu[i].total = stu[i].GE + stu[i].GI;
    }
    sort(stu, stu + N, cmp);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
           if(sch[stu[i].choice[j]].stu_id.size() < sch[stu[i].choice[j]].limit) {
               sch[stu[i].choice[j]].stu_id.push_back(stu[i].id);
               break;
           }
        }
    }

    for(int i = 0; i < M; i++) {
        sort(sch[i].stu_id.begin(), sch[i].stu_id.end());
        for(int j = 0; j < sch[i].stu_id.size(); j++) {
            if(j == 0) {
                cout << sch[i].stu_id[j];
            } else {
                cout << " " << sch[i].stu_id[j];
            }
        }
        if(i != M - 1)
            cout << endl;
    }

    return 0;
}
