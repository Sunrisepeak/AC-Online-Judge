#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    string id;
    int grade;
}stu[10010];
bool cmp(Student A, Student B) {
    return A.grade > B.grade;
}

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> stu[i].name >> stu[i].id >> stu[i].grade;
    }
    int grade1, grade2;
    cin >> grade1 >> grade2;
    sort(stu + 1, stu + N + 1, cmp);
    bool flag = false;
    for(int i = 1; i <= N; i++) {
        if(stu[i].grade >= grade1 && stu[i].grade <= grade2) {
            if(flag)
                cout << endl << stu[i].name << " " << stu[i].id;
            else {
                cout << stu[i].name << " " << stu[i].id;
                flag = true;
            }
        }
    }
    if(!flag)
        cout << "NONE";
    return 0;
}
