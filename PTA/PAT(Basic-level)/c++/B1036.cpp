#include <iostream>

using namespace std;

int main(){
	int N;
	char c;
	scanf("%d %c", &N, &c);
	for(int i = 1; i <= (N + 1)/2; i++){
		for(int j = 1; j <= N; j++){
			if(i == 1 || i == (N + 1)/2 || j == 1 || j == N){
				putchar(c);
			}else{
				putchar(' ');
			}
		}
		putchar('\n');
	}
	return 0;
} 
