#include<iostream>
#include<vector>
#define MaxSize 11
using namespace std;
typedef struct{
	int data[MaxSize];
	int f,t;
}Queue;
typedef char Tree[11][3];
int read(Tree &t)
{
	int N;
	cin >> N;
	int *p = new int[N];
	for(int i = 0; i < N; i++)
	{
		cin >> t[i][1] >> t[i][2];
		if(t[i][1] != '-')
			p[t[i][1] - '0'] = 1;
		if(t[i][2] != '-')
			p[t[i][2] - '0'] = 1;
	}
	int i;
	for(i = 0; i < N; i++)
		if(p[i] != 1)
			break;
	delete [] p;
	return i;
}
void EnQueue(Queue &q, int node)
{
	q.data[++q.t] = node;
}
int main()
{
	int head;
	Tree t;
	head = read(t);
	Queue q;
	q.f = q.t = -1;
	EnQueue(q, head);
	int temp;
	int flag = 1;
	while(q.t != q.f)
	{
		temp = q.data[++q.f];
//		cout << temp <<"---" <<t[temp][1]<<"-----" <<t[temp][2]<<endl;
		if(t[temp][1] != '-')
			EnQueue(q, t[temp][1] - '0');
		if(t[temp][2] != '-')
			EnQueue(q, t[temp][2] - '0');
		if(t[temp][1] == '-' && t[temp][2] == '-')
		{
			printf(flag ? "%d" : " %d", temp);
			flag = 0;
		}
	}
	return 0;
}
