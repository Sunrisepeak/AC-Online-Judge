#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
struct node{
	double num;
	char op;
	bool flag;
};
string str;
stack<node> s;	//op_stack
queue<node> q; //express queue
map<char, int> op;

void Change(){
	double num;
	node temp;
	for(int i = 0; i < str.length();){
		if(str[i] >= '0' && str[i] <= '9'){
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}else if(str[i] == ')'){
			while(!s.empty() && s.top().op != '('){
				q.push(s.top());
//				cout << s.top().op;
				s.pop();
			}
			if(!s.empty())
				s.pop();
			i++;
		}else{
			temp.flag = false;
			while(!s.empty() && s.top().op != '(' &&op[str[i]] <= op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

double Cal(){
	double temp1, temp2;
	node cur, temp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag == true) s.push(cur);
		else{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
//			cout << cur.op << endl;
			switch(cur.op){
				case '+': temp.num = temp1 + temp2; break;
				case '-': temp.num = temp1 - temp2; break;
				case '*': temp.num = temp1 * temp2; break;
				case '/': temp.num = temp1 / temp2; break;
			}
			s.push(temp);
		}
	}
//	cout <<"num = "<< s.top().num <<endl;
	return s.top().num;
}
int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	op['('] = 3;
	while(getline(cin, str) , str != "0"){
		for(string::iterator it = str.end(); it != str.begin(); it--){
			if(*it == ' ') str.erase(it);
		}
		while(!s.empty()) s.pop();
		Change();
		printf("%.2f\n", Cal());
	}
	return 0;
}
