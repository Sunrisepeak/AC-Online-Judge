#include <iostream>
#include <string>
#include <vector>
using namespace std;
using LL = long long;

const LL P = 10000000 + 19;        // spend 1.5h [bin is not dec]
const LL MOD = 1000000000 + 7;     // (1u << 9 + 7) --> error

vector<LL> powP;

void initPow() {
    powP[0] = 1;
    for (int i = 1; i < powP.size(); i++) {         // error-write int i = 0: spend 40m
        powP[i] = (powP[i - 1] * P) % MOD;
        cout << "[i:" << i << "]" << powP[i] << endl;
    }
}

LL hashFunc(string str,vector<LL> &H) {
    H[0] = str[0];
    for (int i = 1; i < str.length(); i++) {
        cout << "[H]: " << H[i - 1] << " * " << P << " + x = ";
        H[i] = H[i - 1] * P + str[i];
        cout << H[i] << " --> ";
        H[i] %= MOD;
        cout << H[i] << endl;
    }
    return H[str.length() - 1];
}

LL subStrHashValue(const vector<LL> &H, int i, int j) {
    if (i == 0) return H[j];
    else if (i > j) return -1;
    cout << H[j] << " " << H[i - 1] << " " << powP[j - i + 1] << endl;
    cout <<"{H[j] - H[i-1] * powP[j - i + 1]} = " << (H[j] - H[i - 1] * powP[j - i + 1]) << " :: " <<
            (H[j] - H[i - 1] * powP[j - i + 1]) % MOD << endl;
    return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    vector<LL> H(str1.length());

    powP.resize(str1.length() + 10);    //[length]
    initPow();
    
    cout << vector<LL>(10, -1).size() << endl;
    
    int rmHv = hashFunc(str2, H);
    cout << "[rmHv]: " << rmHv << endl;
    hashFunc(str1, H);
    string ans;
    bool lastOpIsDel = false;
    for (int i = str2.length() - 1; i < str1.length();) {
        int subH = subStrHashValue(H, i - (str2.length() - 1), i);
        cout << "[debug-subH]: " << subH << endl;
        if (rmHv == subH) {     // rm
            i += str2.length();
            lastOpIsDel = true;
        } else {
            ans += str1.substr(i - (str2.length() - 1), 1);
            cout << "[ans]: " << ans << endl;
            i++;
            lastOpIsDel = false;
        }
    }
    if (lastOpIsDel == false)
        ans += str1.substr(str1.length() - str2.length() + 1);
    cout << ans;
    return 0;
}

/**
 * target:  delete substr(str2) of string(str1)
 * 
 * input:   
 *      hellohello
 *      he 
 * 
 * output:
 *      llollo
 * 
 * timeComplex: O(max{len1, len2})
 * otherTC:
 *      for () {
 *          for () : compare char of string
 *      }
 *      O(len1 * len2)
*/