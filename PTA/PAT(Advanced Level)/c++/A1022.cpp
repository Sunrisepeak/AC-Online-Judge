/*
 * @Author: SPeak Shen 
 * @Date: 2020-05-19 17:50:48 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-05-22 17:55:05
 */


// run time: 465ms
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string id;
    string title;
    string author;
    string keyWords[5];
    string publisher;
    string pubYear;
};

bool cmp(const Book &A, const Book &B) {
    int a = stoi(A.id), b = 10000000;
    if (B.id != "") {
        b = stoi(B.id);
    }
    return a < b;
}

void splitBySpace(string *arr, string str) {
    int p = 0, begin = 0;
    bool lock = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && !lock) {
            arr[p++] = str.substr(begin, i - begin);
            lock = true;
        } else {
            if (lock) {
                begin = i;
                lock = false;
            }
        }
    }
    arr[p] = str.substr(begin, str.length() - begin);
}

bool match(const Book &b, string str) {
    //cout << "queries Info: " <<  str << endl;
    if (
        b.id == str || b.author == str ||
        b.pubYear == str || b.title == str ||
        b.publisher == str
    ) {
        return true;
    }
    for (int i = 0; i < 5; i++) {
        if (b.keyWords[i] == str) {
            return true;
        }
    }
    return false;
}

Book book[10001];

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    string trash;
    cin >> N;  

    //getchar();      // notice: '\n' of the end of a line
    getline(cin, trash);

    for (int i = 0; i < N; i++) {
        getline(cin, book[i].id);
        getline(cin, book[i].title);
        getline(cin, book[i].author);

        getline(cin, book[i].keyWords[0]);
        splitBySpace(book[i].keyWords, book[i].keyWords[0]);
        
        getline(cin, book[i].publisher);
        getline(cin, book[i].pubYear);
    }
    sort(book, book + N, cmp);
    cin >> M;
    
    //getchar();      // notice: '\n'
    getline(cin, trash);

    for (int i = 0; i < M; i++) {
        string queries;
        bool exist = false;
        getline(cin, queries);
        cout << queries << endl;
        for (int j = 0; j < N; j++) {
            if (match(book[j], queries.substr(3, queries.length() - 3))) {
                cout << book[j].id << endl;
                exist = true;
            }
        }
        if (!exist) {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}

/*
 *  it is not notice that 'num:' is type of query 
 *  Notice:
 *      ios::sync_with_stdio(false), getcahr(),
 *      scanf, printf, can't together use.
 */