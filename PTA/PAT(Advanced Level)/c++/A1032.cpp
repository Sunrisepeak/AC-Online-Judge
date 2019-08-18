#include <iostream>
using namespace std;
int Link[100001]{0};
int main(){
	int head1, head2, N;
	cin >> head1 >> head2 >> N;
	int ad1, ad2;
	char c;
	for(int i = 0; i < N; i++){
		scanf("%d %c %d", &ad1, &c, &ad2);
		Link[ad1] = ad2; 
	}
	int p = head1;
	while(p != -1){
		int next = Link[p];
		Link[p] = -2;
		p = next;
	}
	p = head2;	//head2 == -1  ISSUE: 30m
	while(p != -1){
		if(Link[p] == -2){
			printf("%05d", p);
			return 0;
		}
		p = Link[p];
	}
	printf("-1");
}

/*
 * Notes: Address of first Node
 */
