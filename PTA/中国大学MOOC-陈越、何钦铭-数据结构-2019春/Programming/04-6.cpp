#include<iostream>
#include<malloc.h>
#include<string.h>
using std::cin;
using std::cout;
using std::endl;
int sortNode[2001];
int CBST[2001];
int N;
void ReadNodeData()
{
	int x;
	cin >> N;
	int count = N;
	while(count--)
	{
		cin >> x;
		sortNode[x] = 1;
	}
}
void CreateTree(int node_pos,int& data_pos)
{
	if(node_pos <= N)
	{
		CreateTree(node_pos * 2, data_pos);
		while(sortNode[data_pos] != 1) data_pos++;
		CBST[node_pos] = data_pos++;
		CreateTree(node_pos * 2 + 1, data_pos);
	}
}
int main()
{
	memset(sortNode, -1,sizeof(sortNode));
	memset(CBST, -1,sizeof(CBST));
	ReadNodeData();
	int node_pos = 1, data_pos = 0; 
	CreateTree(node_pos, data_pos);
	for(int i = 1; i < N; i++)
		cout << CBST[i] << " ";
	cout << CBST[N] << endl;
	return 0;
}
