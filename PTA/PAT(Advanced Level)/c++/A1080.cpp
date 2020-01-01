#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Student {
    int id, rank;
    int GE, GI;
    vector<int> choice;
    int total;
}stu[40010];

struct School {
    int limit;
    vector<int> ac_stu;
    int last = -1;   //last student index
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

    //rank for Student
    stu[0].rank = 1;
    for(int i = 1; i < N; i++) {
        if(stu[i].total == stu[i -1].total && stu[i].GE == stu[i - 1].GE) {
            stu[i].rank = stu[i - 1].rank;
        } else {
            stu[i].rank = i + 1;
        }
       // cout << ">>" << stu[i].rank << " id:" << stu[i].id << endl;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
           auto &temp = sch[stu[i].choice[j]]; 
           if(temp.ac_stu.size() < temp.limit || (temp.last != -1 && stu[temp.last].rank == stu[i].rank)) {  //enter rule(include break rule when up_rank == now_rank)
               temp.ac_stu.push_back(stu[i].id);
               temp.last = i;
               break;
           }
        }
    }

    for(int i = 0; i < M; i++) {
        sort(sch[i].ac_stu.begin(), sch[i].ac_stu.end());
        for(int j = 0; j < sch[i].ac_stu.size(); j++) {
            if(j == 0) {
                cout << sch[i].ac_stu[j];
            } else {
                cout << " " << sch[i].ac_stu[j];
            }
        }
        cout << endl;
    }
    return 0;
}
