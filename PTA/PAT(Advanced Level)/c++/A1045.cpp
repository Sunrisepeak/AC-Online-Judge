#include <iostream>
#include <vector>
#include <map>

using namespace std;

class FavColor {
    public:
        FavColor() = default;
        FavColor(int c) { colorValue = c; }

        static void setColOrder(const vector<int> &ct) {
            favOrderMap.clear();
            for (int i = 0; i < ct.size(); i++) {   //remap level of fav
                favOrderMap[ct[i]] = i;
            }
        }

        static bool isFavCol(int c) {
            return favOrderMap.find(c) != favOrderMap.end();
        }

        bool operator<=(const FavColor &c) {
            return favOrderMap[colorValue] <= favOrderMap[c.colorValue];
        }
        
        FavColor & operator=(const FavColor &favc) {
            colorValue = favc.colorValue;
            return *this;
        }

        /* FavColor & operator=(const int &c) {        // for implicit-converstion of 
            colorValue = c;                            // func-parameter [int -> FavColor]
            return *this;                              // but can't is '&'
        } */

    private:
        
        int colorValue { 0 };
        static map<int, int> favOrderMap;
};

map<int, int> FavColor::favOrderMap;        // init static vriable of class

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> ct(M);
    for (int i = 0; i < M; i++) {
        cin >> ct[i];
    }
    FavColor::setColOrder(ct);
    vector<FavColor> arr;
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int temp;
        cin >> temp;
        if (FavColor::isFavCol(temp) && temp <= N) {
            // anonymity-obj life circle [?] when it is pass value by func-parameter
            arr.push_back(FavColor(temp));        // implicit-conversion
        }
        //cout << "[size-arr]: " << arr.size()  << " add ? " << temp << endl;
    }
    vector<int> dp(arr.size(), 1);
    // solve sub-problem
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] <= arr[i]) {
                dp[i] = dp[j] + 1;
                break;
            }
        }
        //cout << "[debug]: " << dp[i] << endl;
    }
    int ans = -1;
    for (int i = 0; i < dp.size(); i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    cout << ans;
    return 0;
}