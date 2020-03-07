#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const int M = 26 * 26 * 26 * 10 + 1;

struct hash_tabledent {
    string name{""};
    vector<int> course;
};

vector<hash_tabledent> hash_table(M);
/*
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
*/
int get_id(string name) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id * 26 + name[i] - 'A';
    }
    id = id * 10 + name[3] - '0';
    return id;
}
/*
int get_Hkey(const string &name,const int &size) {
    int key = get_id(name);
    //cout << key << " -- key" << endl;
    for (int i = 0; i <= size / 2; i++) {
        int temp_key = (key + (long long)i * i) % size; // i * i overflow, need longlong
        //cout << temp_key << " -- " << temp_key << endl;
        if (hash_table[temp_key].name == "" || hash_table[temp_key].name == name) {
            return temp_key;
        } 
    }
    return size - 1;
}
*/
int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    /*
    int hash_size = N * 2;
    while (!isPrime(hash_size)) {
        hash_size++;
    }
    hash_table.resize(hash_size);
    */
    //cout << "resize() successful" << endl;
    for (int i = 0; i < K; i++) {
        int c, Ni;
        cin >> c >> Ni;
        string id;
        for (int j = 0; j < Ni; j++) {
            cin >> id;
            
            /*int temp_key = get_Hkey(id, hash_size);
            if (temp_key == -1) {
                cout << "key exception -1" << endl;
            }*/

            int temp_id = get_id(id);
//            cout << temp_id << "  --- temp id " << endl;
            hash_table[temp_id].name = id;
            hash_table[temp_id].course.push_back(c);
        }
    }

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        cout << temp;
        //int key = get_Hkey(temp, hash_size);
        int key = get_id(temp);
        sort(hash_table[key].course.begin(), hash_table[key].course.end());
        cout << " " << hash_table[key].course.size();
        for (auto c : hash_table[key].course) {
            cout << " " << c;
        }
        cout << endl;
    }
    return 0;
}
