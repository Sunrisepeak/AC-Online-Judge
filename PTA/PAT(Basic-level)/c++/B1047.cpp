#include <iostream>
using namespace std;
int score_hash[1010]{ 0 };
int main() {
    int N;
    scanf("%d", &N);
    int id, temp, score;
    int max_index = 0; 
    for(int i = 0; i < N; i++) {
        scanf("%d-%d %d", &id, &temp, &score);
        score_hash[id] += score;
        if(score_hash[id] > score_hash[max_index]) {
            max_index = id;
        }
    }
    printf("%d %d", max_index, score_hash[max_index]);
    return 0;
}
