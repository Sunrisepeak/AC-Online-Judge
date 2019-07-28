#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct People{
    //int level;     // better than this.
	int no, v, t, total_grades;	
};

bool cmp(People a, People b){
	if(a.total_grades != b.total_grades)
		return a.total_grades > b.total_grades;
	else if(a.v != b.v)
		return a.v > b.v;
	else
		return a.no <= b.no;
}

void print(vector<People> v){
	for(int i = 0; i < v.size(); i++){
	//	cout << v[i].no << " " <<
	//		 	v[i].v  << " " << v[i].t << endl;
		printf("%d %d %d\n", v[i].no, v[i].v, v[i].t);
	}
}
int main(){
	vector<People> sage, noble, fool, other;
	ios::sync_with_stdio(false);
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	int a, b, c, count = 0;
	People temp;
	for(int i = 0; i < N; i++){
	//	cin >> a >> b >> c;
		scanf("%d%d%d", &a, &b, &c);
		temp.no = a;
		temp.v = b;
		temp.t = c;
		temp.total_grades = b + c;
		if(b >= L && c >= L){
			if(b >= H && c >= H){
				sage.push_back(temp);
			}else if(b >= H){
				noble.push_back(temp);
			}else if(c < H && b < H && b >= c){
				fool.push_back(temp);
			}else{
				other.push_back(temp);
			}
		}else{
			count++;
		}
	}
	cout << N - count << endl;
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	sort(other.begin(), other.end(), cmp);
	print(sage);
	print(noble);
	print(fool);
	print(other);
	return 0;
}

/* About IO
 *		scanf printf	1m
 *		ios::sync_with_stdio(false);	2.8m
 *		cin, cout 						3.3m
 */
