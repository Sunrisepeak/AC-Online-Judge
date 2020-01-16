#include <iostream>

using namespace std;
struct GStation {
    double price;
    int next_station;
}gs[30010];

int main() {
    int CMax, D, Davg, N;
    cin >> CMax >> D >> Davg >> N;
    double p;
    int temp_pos;
    int _first = D, _last = -1;
    for(int i = 0; i < N; i++) {
        cin >> p >> temp_pos;
        gs[temp_pos].price = p;
        if(_first > temp_pos) {
            _first = temp_pos;
        }
        if(_last < temp_pos) {
            _last = temp_pos;
        }
    }

    if(_first != 0) {
        cout << "The maximum travel distance = " << "0.00";
    } else {
        int temp_next = D;
        for(int i = _last; i >= _first; i--) {
             if(gs[i].price > 0) {
                 if(temp_next - i > Davg * CMax) {
                    printf("The maximum travel distance = %.2lf", static_cast<double>(i) + Davg * CMax);
                    return 0;
                 }
                 gs[i].next_station = temp_next;
                 temp_next = i;
             }
        }
        int present = _first, lowp_pos = gs[present].next_station;
        double ans = 0;
        while(1) {
            bool FIND_LOWER = false;
            for(int i = gs[present].next_station; i <= _last && i < present + CMax + Davg; i = gs[i].next_station) {
                if(gs[i].price < gs[present].price) {
                    ans += gs[present].price * (i - present);
                    present = i;
                    FIND_LOWER = true;
                    break;
                }
                if(gs[lowp_pos].price > gs[i].price) {
                    lowp_pos = i;
                }
            }
            if(!FIND_LOWER) {
               ans +=  
            }
        }
    }
    return 0;
}
