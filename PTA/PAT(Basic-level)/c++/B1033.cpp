#include <iostream>
#include <string>
#include <cstring>
/* Error Init(only if 0 is Ok)
 *  bool keybroad_map[130] = { true }; can't init to true for bool_arr
 *  int test[5] = {1}; 
 */
bool keybroad_map[130];
using namespace std;
int main() {
    string bad_key, input;
    getline(cin, bad_key);
    getline(cin, input);
    memset(keybroad_map, true, sizeof(keybroad_map));
    for(auto c : bad_key) {    
        keybroad_map[c] = false;
        if(isupper(c)) {
            keybroad_map[tolower(c)] = false;
        } else {
            keybroad_map[toupper(c)] = false;
        } 
    }
    for(auto c : input) {
        if(isupper(c)) {
            if(keybroad_map['+'] && keybroad_map[c]) {
                cout << c;
            }
        } else {
    //     cout << "Debug -- " << c << "  " <<keybroad_map[c] <<endl; 
           if(keybroad_map[c])
               cout << c;
        }
    }
    return 0;
}
