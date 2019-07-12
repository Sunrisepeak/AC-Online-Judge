#include <iostream>
using namespace std;

typedef struct{
	int exp;
	double coef;
}Poly;

Poly operator + (const Poly& A, const Poly& B){
	Poly temp;
//	temp.exp = A.exp + B.exp;	//ISSUE0: logical error: 20m
	temp.exp = A.exp;
	temp.coef = A.coef + B.coef;
	return temp;
}

void bToA(Poly& A, const Poly& B){
	A.exp = B.exp;
	A.coef = A.coef;
}
int main(){
	Poly a[11][2], c[21];
	int K[2];
	for(int i = 0; i < 2; i++){
		cin >> K[i];
		Poly t;
		for(int j = 0; j < K[i]; j++){
			cin >> t.exp >> t.coef;
			a[j][i] = t;
	//		cout << a[j][i].coef << endl;
		}
	}
	
	int k0{0}, k1{0}, ans_count = 0;
	while(k0 < K[0] && k1 < K[1]){
		if(a[k0][0].exp > a[k1][1].exp){
			c[ans_count++] = a[k0++][0];
		}else if(a[k0][0].exp == a[k1][1].exp){
			c[ans_count] = a[k0++][0] + a[k1++][1];
			if(c[ans_count].coef != 0.)	//ISSUE1: judge 0: 20m 
				ans_count++;	
		}else{
			c[ans_count++] = a[k1++][1];
		}
	}
	while(k0 < K[0]) c[ans_count++] = a[k0++][0];
	while(k1 < K[1]) //c[ans_count++] = a[k1++][0];	//ISSUE2: index error, spend 20m
		c[ans_count++] = a[k1++][1];
	cout << ans_count;
	for(int i = 0; i < ans_count; i++){
	//	cout << " " << c[i].exp << " " << c[i].coef;
        printf(" %d %.1f",c[i].exp, c[i].coef);		//ISSUE3: format: 1hour
	} 
	return 0;
}

/*
Summary:
	
*/
