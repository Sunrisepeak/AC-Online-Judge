#include <iostream>
#include <algorithm>
using namespace std;
struct Moon {
//    int save; // lead to Wrong Answer, becase of can "(double / int) * int != double "
    double save;
    double per_price;
}moon[1010];
bool cmp(Moon A, Moon B) {
    return A.per_price > B.per_price;
}
int main() {
    int N, D;
    cin >> N >> D;
    for(int i = 0; i < N; i++) {
        cin >> moon[i].save;
    }
    double temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        moon[i].per_price = temp / moon[i].save;
    }
    sort(moon, moon + N, cmp);
    double max_profit{ 0 };
    for(int i = 0; i < N; i++) {
        if(moon[i].save > D) {
            max_profit += D * moon[i].per_price;
            break;
        } else {
            max_profit += moon[i].save * moon[i].per_price;
            D -= moon[i].save;
        }
//        cout << "max_profit : " << max_profit << endl;
    }
    printf("%.2lf", max_profit);
    return 0;
}
